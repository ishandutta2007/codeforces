//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 85 - 69,
	  maxl = 20;
int a[maxn],
	h[maxn],
	bachcnt[maxn],
	par[maxn][maxl],
	n;
set<pii> s;

int kthpar(int v, int k){
	for(int i = 0; i < maxl; i++)
		if((k >> i) & 1)
			v = par[v][i];
	return v;
}

int lca(int v, int u){
	if(h[v] < h[u])
		swap(v, u);
	v = kthpar(v, h[v] - h[u]);
	if(v == u)
		return v;
	for(int i = maxl - 1; i >= 0; i--)
		if(par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

void add(int p, int v){
	bachcnt[p]++;
	h[v] = h[p] + 1;
	par[v][0] = p;
	for(int j = 1; j < maxl and par[v][j - 1] != -1; j++)
		par[v][j] = par[par[v][j - 1]][j - 1];
	if(bachcnt[p] == 2)
		s.erase(MP(a[p], p));
	s.insert(MP(a[v], v));
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	s.insert(MP(a[0], 0));
	for(int i = 1; i < n; i++){
		auto it = s.lower_bound(MP(a[i], i));
		if(sz(s) == 0){
			cout << "GOH NAKHOR!!!" << endl;
			return 0;
		}
		if(it == s.end()){
			it--;
			add(it->R, i);
		}
		else if(it == s.begin())
			add(it->R, i);
		else{
			int p2 = it->R;
			it--;
			int p1 = it->R;
			int p = lca(p1, p2);
			if(a[i] < a[p])
				add(p1, i);
			else
				add(p2, i);
		}
	}
	for(int i = 1; i < n; i++){
		if(par[i][0] == -1){
			cout << "GOH" << endl;
			return 0;
		}
		cout << a[par[i][0]] << " \n"[i == n - 1];
	}
	return 0;
}