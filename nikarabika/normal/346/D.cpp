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

const int maxn = 1e6 + 85 - 69;
vector<int> jda[maxn],
	vec[maxn],
	tmp;
int odeg[maxn],
	func[maxn],
	mn[maxn],
	mx[maxn],
	n, m, syn, sou;
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(mn, 63, sizeof mn);
	memset(mx, -1, sizeof mx);
	memset(func, -1, sizeof func);
	tmp.reserve(1 << 20);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		jda[se].PB(fi);
		odeg[fi]++;
	}
	cin >> sou >> syn;
	sou--, syn--;
	mn[syn] = 0, mx[syn] = 0;
	vec[0].PB(syn);
	func[syn] = 0;
	for(int i = 0; i < n; i++){
		for(int ii = 0; ii < sz(vec[i]); ii++){
			int u = vec[i][ii];
			for(auto v : jda[u]){
				odeg[v]--;
				smin(mn[v], func[u]);
				smax(mx[v], func[u]);
				if(odeg[v] == 0){
					func[v] = func[u];
					vec[func[v]].PB(v);
				}
				else if(odeg[v] > 0)
					tmp.PB(v);
			}
		}
		for(auto u : tmp) if(odeg[u] > 0){
			func[u] = i+1;
			odeg[u] = 0;
			vec[i+1].PB(u);
		}
		tmp.clear();
	}
	cout << func[sou] << '\n';
	return 0;
}