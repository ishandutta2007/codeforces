//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

#undef right
#define right Right
#define endl '\n'

const int maxn = 2e5 + 85 - 69;
int par[maxn], right[maxn];
int n, q;

int root(int x){return (par[x] < 0) ? x : par[x] = root(par[x]);}
int rightest(int x){return (right[x] == x) ? x : right[x] = rightest(right[x]);}

void merge(int fi, int se){
	if((fi = root(fi)) == (se = root(se)))
		return;
	if(par[fi] > par[se])
		swap(fi, se);
	par[fi] += par[se];
	par[se] = fi;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		right[i] = i;
	while(q--){
		int ty, fi, se;
		cin >> ty >> fi >> se;
		if(ty == 1)
			merge(fi, se);
		else if(ty == 2){
			while(fi <= se){
				merge(fi, se);
				int temp = fi;
				fi = rightest(fi) + 1;
				right[temp] = se;
			}
		}
		else
			cout << (root(fi) == root(se) ? "YES" : "NO") << endl;
	}
	return 0;
}