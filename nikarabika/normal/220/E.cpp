/*
ID: bug-overflow
TASK: CF220E
LANG: C++11
*/

//manam A _____ & an O_o waiting to see U :)

#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define sz(x) ((int)(x).size())
#define PB push_back

const int maxn = 1e5 + 85 - 69;
LL inv, n, k, ans;
int a[maxn], indexof[maxn];
vector<int> all;

struct fenwick_tree{
	LL a[maxn];
	int n;
	fenwick_tree(){
		memset(a, 0, sizeof a);
	}
	int operator[](int i){
		return a[i];
	}
	void add(int idx, LL val){
		if(idx == 0)
			return;
		while(idx <= n){
			a[idx] += val;
			idx += idx & -idx;
		}
		return;
	}
	LL get(int idx){
		LL ret = 0;
		while(idx > 0){
			ret += a[idx];
			idx -= idx & -idx;
		}
		return ret;
	}
	LL get(int st, int en){
		if(en < st)
			return 0;
		return get(en) - get(st - 1);
	}
} fen_left, fen_right;

LL calc_invs(int idx){
	return fen_left.get(idx + 1, fen_left.n) + fen_right.get(1, idx - 1);
}

bool can_add(int idx, bool dir){
	if(inv + calc_invs(idx) <= k){
		inv += calc_invs(idx);
		dir ? fen_right.add(idx, 1) : fen_left.add(idx, 1);
		return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	fen_left.n = fen_right.n = sz(all);
	for(int i = 0; i < n; i++)
		indexof[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
	LL p = 0, q = n;
	while(p < n - 1 and can_add(indexof[p], 0))
		p++;
	p--;
	while(p >= 0){
		while(q - 1 > p and can_add(indexof[q - 1], 1))
			q--;
		//cout << p << ' ' << q << ' ' << inv << ' ';
		ans += n - q;
		int idx = indexof[p];
		fen_left.add(idx, -1);
		inv -= calc_invs(idx);
		//cout << calc_invs(idx) << endl;
		p--;
	}
	cout << ans << endl;
	return 0;
}