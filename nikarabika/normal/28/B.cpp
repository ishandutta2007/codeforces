#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef pair<int, int> pie;

const int maxn = 100 + 85 - 85 + 1;
int par[maxn];
vector<pie> e;
int n, a[maxn];

int root(int x){ return (par[x] < 0) ? x : par[x] = root(par[x]);}

void merge(int x, int y){
	if((x = root(x)) == (y = root(y)))
		return;
	if(par[x] > par[y])
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(par, -1, sizeof par);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(i + x <= n)
			e.PB(MP(i, i + x));
		if(i - x > 0)
			e.PB(MP(i, i - x));
	}
	for(int i = 0; i < e.size(); i++)
		merge(e[i].L, e[i].R);
	for(int i = 1; i <= n; i++){
		if(root(i) != root(a[i])){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}