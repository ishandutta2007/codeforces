#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define double long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 10)
#define MAX2 (int)(3*pow(10,2) + 4)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;




ll dt[MAX][2];
vector<ll> g[MAX];

void dij(ll source, ll n, ll kd){
//	cout<<"!!!! exe for "<<source+1<<endl;
	priority_queue<pair<ll,ll> , vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
	fori(n){
		dt[i][kd] = inf;
	}
	dt[source][kd] = 0;
	pq.push(mp(0, source));
	while(pq.size()){
		auto tp = pq.top();
		pq.pop();
		ll hd = tp.ss;
		if(dt[hd][kd] != tp.ff){
			continue;
		}
		
	//	cout<<"top guy "<<hd+1<<" with distance "<<dt[hd][kd]<<endl;
		
		for(auto& hr: g[hd]){
			if(dt[hd][kd] + 1 < dt[hr][kd]){
				dt[hr][kd] = dt[hd][kd] + 1;
				pq.push(mp(dt[hr][kd], hr));
			}
		}
	}
}
 
 
void deal(){
	ll t = 1;
//	cin>>t;
	while(t--){
		ll n, m, k;
		cin>>n>>m>>k;
		vector<ll> sp(k);
		multiset<ll> all;
		fori(k){
			cin>>sp[i];
			--sp[i];
		}
		fori(m){
			ll x,y;
			cin>>x>>y;
			--x, --y;
			g[x].pb(y);
			g[y].pb(x);
		}
		dij(0, n, 0);
		dij(n-1, n, 1);
		fori(k){
	//		cout<<"special "<<i<<" is "<<sp[i]<<" distance is "<<dt[sp[i]][0]<<endl;
			all.insert(dt[sp[i]][0]);
		}
		ll mx  = 0;
		
		vector<pair<ll,ll> > dist;
		vector<pair<ll,ll> > tomax(k);
		fori(k){
			dist.pb(mp(dt[sp[i]][0], dt[sp[i]][1]));
		}
		sort(dist.begin(), dist.end());
		
		pair<ll,ll> last = mp(-inf, -inf);
		for(ll i = k-1; i>-1; i--){
			tomax[i] = last;
			if(dist[i].ss > tomax[i].ff){
				tomax[i].ss = tomax[i].ff;
				tomax[i].ff = dist[i].ss;
			}
			else if(dist[i].ss > tomax[i].ss){
				tomax[i].ss = dist[i].ss;
			}
			last = tomax[i];
		}
		
		fori(k){
			ll lo = 0 , hi  = inf;
			
			// first distance we can do
			while(lo < hi){
				ll mid = (lo + hi ) /2 + 1;
				ll xdist = mid - dist[i].ss;
				ll ydist = mid - dist[i].ff;
				if(dist[k-1].ff < xdist){
					hi = mid-1;
					continue;
				}
				ll lo1 = 0, hi1 = k-1;
				while(lo1 < hi1){
					ll mid1 = (lo1+hi1)/2;
					if(dist[mid1].ff >= xdist){
						hi1 = mid1;
					}
					else{
						lo1 = mid1+1;
					}
				}
				ll lz = tomax[lo1].ff;
				if(dist[i].ff >= xdist && lz == dist[i].ss){
					lz = tomax[lo1].ss;
				}
				if(lz >= ydist){
					lo = mid;
				}
				else{
					hi = mid-1;
				}
			}
	//		cout<<"we can do "<<lo<<" distance for the guy "<<dist[i].ff<<" "<<dist[i].ss<<endl;
			
			ll mn = min(dt[n-1][0], lo+1);
			mx = max(mx, mn);
		}
		
		cout<<mx<<'\n';
	}
	
	
}
  
  
  
  
  
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}