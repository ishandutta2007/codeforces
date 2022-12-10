/*
ID: bug-overflow
TASK: CF61E
LANG: C++11
*/

//manam A _____ & an O_o waiting 2CU...

#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back
#define sz(x) ((int)(x).size())

const int maxn = 1e6 + 85 - 69;
LL dota[maxn], yeta[maxn];
LL ans;
int n, a[maxn];
vector<int> all;

void add(LL *fen, int idx, LL val){
	while(idx <= sz(all)){
		fen[idx] += val;
		idx += idx & -idx;
	}
	return;
}

LL get(LL *fen, int idx){
	LL ret = 0;
	while(idx > 0){
		ret += fen[idx];
		idx -= idx & -idx;
	}
	return ret;
}

LL get(LL *fen, int st, int en){
	return get(fen, en) - get(fen, st - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	all.PB(0);
	all.PB(1e9 + 100);
	sort(all.begin(), all.end());
	for(int i = 0; i < n; i++){
		int id = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
		ans += get(dota, id + 1, sz(all));
		add(dota, id, get(yeta, id + 1, sz(all)));
		add(yeta, id, 1);
	}
	cout << ans << endl;
	return 0;
}