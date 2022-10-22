#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#define debug(x) cerr << "[" << #x << "] = [" << x << "]\n"

template<class A, class B> ostream& operator<< (ostream& out, pair<A, B> p) {
	return out << '[' << p.first << ", " << p.second << ']';
}

template<class T> ostream& operator<< (ostream& out, vector<T>& v) {
	out << '[';
	for (int i = 0; i < v.size(); ++i) {
		if (i > 0) {
			out << ", ";
		}
		out << v[i];
	}
	return out << ']';
}

vector<vector<int>> things;
vector<vector<int>> ans;

vector<int> combine(vector<int> a, vector<int> b) {
	vector<int> res = a;
	for (int i : b) {
		res.push_back(i);
	}
	return res;
}

void print() {
	debug(things);
}

vector<int> getPos() {
	assert(things.size() > 1);
	int n = things.size();
	vector<int> inds(n);
	iota(inds.begin(), inds.end(), 0);
	sort(inds.begin(), inds.end(), [](int a, int b) {return things[a] < things[b];});
	vector<int> pos(n);
	for (int i = 0; i < n; ++i) {
		pos[inds[i]] = i;
	}
	return pos;
}

bool check() {
	assert(things.size() > 1);
	int n = things.size();
	vector<int> pos = getPos();
	for (int i = 0; i + 1 < n; ++i) {
		if (pos[i + 1] == pos[i] + 1) {
			vector<int> x = combine(things[i], things[i + 1]);
			things.erase(things.begin() + i);
			things[i] = x;
			return 1;
		}
	}
	return 0;
}

void helper(vector<int> v) {
	int n = things.size();
	vector<vector<int>> nxt;
	assert(accumulate(v.begin(), v.end(), 0) == things.size());

	vector<int> h;
	int ind = 0;
	for (int i = 0; i < v.size(); ++i) {
		int ind2 = ind + v[i];
		int cur = 0;
		for (int j = ind; j < ind2; ++j) {
			cur += things[j].size();
		}
		h.push_back(cur);
		ind = ind2;
	}
	ans.push_back(h);
	assert(ind == n);

	//ind = n;
	for (int i = v.size() - 1; i >= 0; --i) {
		int first = ind - v[i];
		for (int j = first; j < ind; ++j) {
			nxt.push_back(things[j]);
		}
		ind = first;
	}
	assert(ind == 0);
	things = nxt;
}

void solve() {
	int n = things.size();
	assert(n > 1 && !check());
	//debug(things);
	if (n == 2) {
		helper({1, 1});
		return;
	}
	vector<int> pos = getPos();// debug(pos);
	vector<int> cur;
	if (pos[0] == 0) {
		cur.push_back(1);
		assert(pos[1] > 1);
		int x = find(pos.begin(), pos.end(), pos[1] - 1) - pos.begin();
		cur.push_back(x - 1);
		for (int i = x; i < n; ++i) {
			cur.push_back(1);
		}
	}
	else {
		assert(pos[0] > 0);
		int x = find(pos.begin(), pos.end(), pos[0] - 1) - pos.begin();
		cur.push_back(x);
		for (int i = x; i < n; ++i) {
			cur.push_back(1);
		}
	}
	helper(cur);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		things.push_back({a});
	}
	while(things.size() > 1 && check());
	while(things.size() > 1) {
		solve();
		while(things.size() > 1 && check());
		//debug(things);
	}
	assert(ans.size() <= n);
	cout << ans.size() << "\n";
	for (auto x : ans) {
		cout << x.size();
		assert(accumulate(x.begin(), x.end(), 0) == n);
		for (int i : x) {
			cout << " " << i;
		}
		cout << "\n";
	}
	return 0;
}