#include <bits/stdc++.h>
using namespace std;

const int BLOCK_SIZE = 3500;

struct Query {
	int t, l, r, idx;

	Query(int T, int L, int R, int ID) {
		t = T, l = L, r = R, idx = ID;
	}

	bool operator<(Query other) const {
		if (l / BLOCK_SIZE != other.l / BLOCK_SIZE)
			return l < other.l;
		if (r / BLOCK_SIZE != other.r / BLOCK_SIZE)
			return r < other.r;
		else
			return t < other.t;
	}
};

struct Update {
	int idx, prev, now;

	Update(int ID, int P, int N) {
		idx = ID; prev = P; now = N;
	}
};

set<int> to_comp;
map<int, int> id;

void coordinate_compression() {
	int petr = 0;
	for (int i: to_comp) {
		id[i] = petr++;
	}
}

int n, q;
vector<int> a(100001);

vector<Query> queries;
vector<Update> updates;

vector<int> cnt(200001);
vector<int> ccnt(100001);

void add(int id) {
	ccnt[cnt[a[id]]]--;
	cnt[a[id]]++;
	ccnt[cnt[a[id]]]++;
}

void remove(int id) {
	ccnt[cnt[a[id]]]--;
	cnt[a[id]]--;
	ccnt[cnt[a[id]]]++;
}

void apply(int id, int val, int l, int r) {
	if (l <= id && id <= r) {
		remove(id);
		a[id] = val;
		add(id);
	} else {
		a[id] = val;
	}
}

int get_answer() {
	for (int i = 0;; i++) {
		if (ccnt[i] == 0) return i; 
	}
	return -1;
}

vector<int> Mo() {
	vector<int> ans(queries.size());
	sort(queries.begin(), queries.end());

	int cur_l = 0, cur_r = -1, cur_t = 0;
	// invariant: data structure will always reflect the range [cur_l, cur_r]
	for (Query q : queries) {
		while (cur_l > q.l) {
			cur_l--;
			add(cur_l);
		}
		while (cur_r < q.r) {
			cur_r++;
			add(cur_r);
		}
		while (cur_l < q.l) {
			remove(cur_l);
			cur_l++;
		}
		while (cur_r > q.r) {
			remove(cur_r);
			cur_r--;
		}
		while (cur_t < q.t) {
			apply(updates[cur_t].idx, updates[cur_t].now, cur_l, cur_r);
			cur_t++;
		}
		while (cur_t > q.t) {
			cur_t--;
			apply(updates[cur_t].idx, updates[cur_t].prev, cur_l, cur_r);
		}
		ans[q.idx] = get_answer();
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q; ccnt[0] = 10000000;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		to_comp.insert(a[i]);
	}
	
	vector<int> t(q), l(q), r(q);
	for (int i = 0; i < q; i++) {
		cin >> t[i] >> l[i] >> r[i];
		if (t[i] == 1) {
			l[i]--; r[i]--;
		} else {
			l[i]--; to_comp.insert(r[i]);
		}
	}

	coordinate_compression();
	for (int i = 0; i < n; i++) {
		a[i] = id[a[i]];
	}
	vector<int> acpy = a;

	for (int i = 0; i < q; i++) {
		if (t[i] == 1) {
			queries.push_back(Query(updates.size(), l[i], r[i], queries.size()));
		} else {
			r[i] = id[r[i]];
			updates.push_back(Update(l[i], acpy[l[i]], r[i]));
			acpy[l[i]] = r[i];
		}
	}

	vector<int> ans = Mo();
	for (int i: ans) cout << i << '\n';

	return 0;
}