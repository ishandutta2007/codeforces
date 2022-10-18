#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

const ll N = 15;
bool adj[N][N];
bool path[1 << N][N][N];

ll ear[1 << N][N][N];
ll pred_ear[1 << N][N][N];
ll cost[1 << N];
tuple<ll,ll,ll> pred[1 << N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m;
	cin >> n >> m;
	while (m--) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		adj[a][b] = adj[b][a] = 1;
	}
	
	memset(pred_ear,-1,sizeof pred_ear);
	FOR(i,0,n) FOR(j,0,n) if (adj[i][j]) {
		ear[(1 << i) | (1 << j)][i][j] = 1;
		pred_ear[(1 << i) | (1 << j)][i][j] = i;
	}
	
	FOR(mask,0,1 << n) FOR(i,0,n) FOR(j,0,n) if (i != j && ear[mask][i][j]) {
		FOR(k,0,n) if (adj[j][k]) {
			if ((k == i && __builtin_popcount(mask) > 2)) {
				ear[mask][i][i] = true;
				pred_ear[mask][i][i] = j;
			}
			if (!(mask & (1 << k))) {
				ear[mask | (1 << k)][i][k] = true;
				pred_ear[mask | (1 << k)][i][k] = j;
			}
		}
	}
	
	memset(cost,0x3f,sizeof cost);
	cost[1] = 0;
	
	FOR(mask,0,1 << n) if (cost[mask] < oo) {
		FOR(i,0,n) if (mask & (1 << i)) {
			FOR(j,0,n) if (mask & (1 << j)) {
				ll cmask = ((1 << n) - 1) ^ mask;
				for (ll smask = cmask; smask; smask = (smask-1) & cmask) {
					ll emask = smask | (1 << i) | (1 << j);
					if (ear[emask][i][j]) {
						ll ncost = cost[mask] + __builtin_popcount(emask) - (i != j);
						if (ncost < cost[mask | emask]) {
							cost[mask | emask] = ncost;
							pred[mask | emask] = make_tuple(emask,i,j);
						}
					}
				}
			}
		}
	}
	
	ll mask = (1 << n) - 1;
	cout << cost[mask] << endl;
	
	while (mask > 1) {
		ll emask, i, j;
		tie(emask,i,j) = pred[mask];

		mask ^= emask;
		mask |= (1 << i) | (1 << j);
		
		TR(emask);
		TR(i);
		TR(j);
		while (pred_ear[emask][i][j] != -1) {
			ll k = pred_ear[emask][i][j];
			cout << k+1 << " " << j+1 << endl;
			if (i != j) emask ^= 1 << j;
			j = k;
		}
	}
}