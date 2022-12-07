#include <bits/stdc++.h>

using namespace std;

const int N = 500500;

int n;
pair < int, int > q[N];

template < class T > 
struct SegmentTreeSum{
	T it[N << 2];
	T lazy[N << 3];

	#define mid ((l + r) >> 1)

	void Init(){
		memset(it, 0, sizeof it);
		memset(lazy, 0, sizeof lazy);
	}

	void push(int x, int l, int r){
		it[x] += lazy[x] * (r - l + 1);
		lazy[x + x] += lazy[x];
		lazy[x + x + 1] += lazy[x];
		lazy[x] = 0;
	}

	void update(int x, int l, int r, int u, int v, T val){
		if(v < u) return;
		push(x, l, r);
		if(l > v || r < u) return;
		if(l >= u && r <= v){
			lazy[x] += val;
			push(x, l, r);
			return;
		}
		update(x + x, l, mid, u, v, val);
		update(x + x + 1, mid + 1, r, u, v, val);
		it[x] = it[x + x] + it[x + x + 1];	
	}

	void modify(int x, int l, int r, int pos, T val){
		push(x, l, r);
		if(l > pos || r < pos) return;
		if(l == r) {
			it[x] = val;
			return;
		}
		modify(x + x, l, mid, pos, val);
		modify(x + x + 1, mid + 1, r, pos, val);
		it[x] = it[x + x] + it[x + x + 1];
	}


	T query(int x, int l, int r, int u, int v){
		push(x, l, r);
		if(u > v) return 0;
		if(l > v || r < u) return 0;
		if(l >= u && r <= v) return it[x];
		T ret = query(x + x, l, mid, u, v) + query(x + x + 1, mid + 1, r, u, v);
		it[x] = it[x + x] + it[x + x + 1];
		return ret;
	}

};

SegmentTreeSum < long long > smt, cnt;

struct SegmentTreeMax{
	int it[N << 2];
	int lazy[N << 3];

	#define mid ((l + r) >> 1)

	void Init(){
		memset(it, 0, sizeof it);
		memset(lazy, 0, sizeof lazy);
	}

	void push(int x){
		it[x] += lazy[x];
		lazy[x + x] += lazy[x];
		lazy[x + x + 1] += lazy[x];
		lazy[x] = 0;
	}

	void update(int x, int l, int r, int u, int v, int val){
		if(v < u) return;
		push(x);
		if(l > v || r < u) return;
		if(l >= u && r <= v){
			lazy[x] += val;
			push(x);
			return;
		}
		update(x + x, l, mid, u, v, val);
		update(x + x + 1, mid + 1, r, u, v, val);
		it[x] = max(it[x + x], it[x + x + 1]);	
	}

	void modify(int x, int l, int r, int pos, int val){
		push(x);
		if(l > pos || r < pos) return;
		it[x] = max(it[x], val);
		if(l == r) return;
		modify(x + x, l, mid, pos, val);
		modify(x + x + 1, mid + 1, r, pos, val);
		it[x] = max(it[x + x], it[x + x + 1]);
	}

	int query(int x, int l, int r, int u, int v){
		push(x);
		if(u > v) return 0;
		if(l > v || r < u) return 0;
		if(l >= u && r <= v) return it[x];
		int ret = max(query(x + x, l, mid, u, v), query(x + x + 1, mid + 1, r, u, v));
		it[x] = max(it[x + x], it[x + x + 1]);
		return ret;
	}
}lst;

int mx;
double ans;

void solve(int x, int l, int r, long long currSum = 0, int curCnt = 0, int curMx = 0){

	smt.push(x, l, r);
	cnt.push(x, l, r);
	lst.push(x);



	if(l != r && lst.it[x] == mx ){
		solve(x + x, l, mid, currSum, curCnt, curMx);
		return;
	}


	if(double(currSum + smt.it[x] + mx) / double(curCnt + cnt.it[x] + 1) >= max(curMx, lst.it[x])){
		ans = double(mx) - double(currSum + smt.it[x] + mx) / double(curCnt + cnt.it[x] + 1);
		//cout << double(currSum + smt.it[x] + mx) / double(curCnt + cnt.it[x] + 1) << " " << double(curCnt + cnt.it[x] + 1) << endl;
		return;
	}


	if(l == r) return;


	if(double(currSum + smt.it[x + x] + mx) / double(curCnt + cnt.it[x + x] + 1) >= max(curMx, lst.it[x + x])){
		ans = (mx - double(currSum + smt.it[x + x] + mx) / double(curCnt + cnt.it[x + x] + 1));
		solve(x + x + 1, mid + 1, r, currSum + smt.it[x + x], curCnt + cnt.it[x + x], max(curMx, lst.it[x + x]));
		return;
	}
	solve(x + x, l, mid, currSum, curCnt, curMx);
}

int main(){

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	scanf("%d", &n);

	vector < int > vals(1, 0);

	for(int i = 1; i <= n; ++i){
		int t, x = 0;
		scanf("%d", &t);

		if(t == 1){
			scanf("%d", &x);
			vals.push_back(x);
		}

		q[i] = make_pair(t, x);
	}

	cout << fixed << setprecision(7);

	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

	int m = vals.size() - 1;


	for(int i = 1; i <= n; ++i){
		//cout << q[i] << endl;
		if(q[i].first == 1){
			int idx = lower_bound(vals.begin(), vals.end(), q[i].second) - vals.begin();
//				cout << idx << endl;

			cnt.update(1, 1, m, idx, idx, 1);
			smt.update(1, 1, m, idx, idx, q[i].second);
			lst.modify(1, 1, m, idx, q[i].second);
	
			mx = max(mx, q[i].second);

		//	cout << mx << endl;
 		}
		else{
			ans = 0;
			solve(1, 1, m);
			cout << ans << '\n';
		}
	}


	return 0;
}