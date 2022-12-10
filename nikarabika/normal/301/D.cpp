//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Iz wayTn' 230u :)

typedef long long int LL;
typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define endl '\n'

const int maxn = 2e5 + 85 - 69;
int fen[maxn], pos[maxn], ans[maxn];
vector<int> baz[maxn], bast[maxn], List[maxn];
vector<pii> quer;
int n, m;

void inc(int idx){
	idx++;
	while(idx <= n){
		fen[idx]++;
		idx += idx & -idx;
	}
	return;
}

int get(int idx){
	int ret = 0;
	while(idx){
		ret += fen[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int get(int st, int en){
	return get(en + 1) - get(st);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		pos[x] = i;
	}
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j += i)
			List[pos[j]].PB(pos[i]);
	for(int i = 0; i < m; i++){
		int fi, se;
		scanf("%d%d", &fi, &se);
		fi--, se--;
		quer.PB(MP(fi, se));
		if(fi != 0)
			baz[fi - 1].PB(i);
		bast[se].PB(i);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < sz(List[i]); j++)
			inc(List[i][j]);
		for(int j = 0; j < sz(baz[i]); j++)
			ans[baz[i][j]] -= get(quer[baz[i][j]].L, quer[baz[i][j]].R);
		for(int j = 0; j < sz(bast[i]); j++)
			ans[bast[i][j]] += get(quer[bast[i][j]].L, quer[bast[i][j]].R);
	}
	for(int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	return 0;
}