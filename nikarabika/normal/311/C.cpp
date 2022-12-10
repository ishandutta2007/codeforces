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

const int maxn = 1e5 + 85 - 69;
LL len,
   dis[maxn],
   a[maxn],
   c[maxn];
set<pll> s, dij;
LL n, m, k;
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> len >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> c[i];
		a[i]--;
		if(a[i] % k == 0)
			s.insert(MP(c[i], -i));
	}
	memset(dis, 63, sizeof dis);
	dis[0] = 0;
	for(int i = 0; i < m; i++){
		LL ty, fi, se;
		cin >> ty;
		if(ty == 1){
			cin >> fi;
			for(int j = 0; j < k; j++)
				dij.insert(MP(dis[j], j));
			while(sz(dij)){
				int u = dij.begin()->R;
				dij.erase(dij.begin());
				int v = (u + fi) % k;
				if(dis[u] + fi < dis[v]){
					dij.erase(MP(dis[v], v));
					dis[v] = dis[u] + fi;
					dij.insert(MP(dis[v], v));
				}
			}
			s.clear();
			for(int j = 0; j < n; j++)
				if(!mark[j] and dis[a[j] % k] <= a[j])
					s.insert(MP(c[j], -j));
		}
		else if(ty == 2){
			cin >> fi >> se, fi--;
			s.erase(MP(c[fi], -fi));
			c[fi] -= se;
			if(!mark[fi] and dis[a[fi] % k] <= a[fi])
				s.insert(MP(c[fi], -fi));
		}
		else if(sz(s)){
			cout << s.rbegin()->L << '\n';
			mark[-s.rbegin()->R] = true;
			s.erase(*s.rbegin());
		}
		else
			cout << 0 << '\n';
	}
	return 0;
}