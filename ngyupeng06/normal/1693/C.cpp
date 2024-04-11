#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;
ll a, b;
vector<int> v[200005], v1[200005];
ll dist[200005];
ll d[200005];
bool vis[200005];
priority_queue<pll, vector<pll>, greater<pll> > pq;
map<ll, ll> ma;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; i++){
		cin >> a >> b;
		v1[a].pb(b);
		d[a]++;
		v[b].pb(a);
	}
	dist[n] = 0;
	for (int i=1; i<n; i++){
		dist[i] = 2e12;	
	}
	pq.push(mp(0,n));
	while (!pq.empty()){
		ll x = pq.top().second;
		pq.pop();
		if (vis[x]) continue;
		vis[x] = true;
		for (auto it : v[x]){
			d[it]--;
			dist[it] = min(dist[it], dist[x] + d[it] + 1);
			pq.push(mp(dist[it], it));
		}
	}
	cout << dist[1];
}