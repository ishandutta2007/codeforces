#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")


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
#define lll __int128
#define pb(a) push_back(a)
#define mt make_tuple
typedef  double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
ll modulo = pow(10,9) + 7;

#define MAX 100100
#define MAX2 20

ll valn[MAX];
ll val[MAX];
ll dp[MAX];

vector<ll> sorted[MAX];

vector<ll> g[MAX];
ll lca[MAX][MAX2];
ll dep[MAX];
ll tin[MAX];
ll tout[MAX];
 
ll calcval(ll a, ll b){
	return max(abs(a + b), abs(a - b));
}
 
void dfslca(ll hd, ll pr, ll& tim){
	lca[hd][0] = pr;
	tin[hd] = tim;
	for(auto hr : g[hd]){
		if(hr == pr)
			continue;
		dep[hr ] = dep[hd]+ 1; 
		++tim;
		sorted[hd].pb(hr);
//		cout<<"we push "<<hr+1<<" to "<<hd+1<<" size of "<<hd+1<<" sorted is "<<sorted[hd].size()<<endl;
		dfslca(hr, hd, tim);
	}
	tout[hd] = tim;
}
 
void pre(ll n){
	for(ll j = 1; j<MAX2; j++)
		fori(n)
			lca[i][j]=  lca[lca[i][j-1]][j-1];
}
 
ll LCA(ll a, ll b){
	if(dep[a] < dep[b])
		swap(a,b);
	// a is deeper now, swim a upwards
	for(ll j = MAX2-1; j>-1; j--)
		if(dep[lca[a][j]] > dep[b])
			a = lca[a][j];
	if(dep[a] != dep[b])
		a = lca[a][0];
	for(ll j=MAX2-1; j>-1; j--)
		if(lca[a][j]!=lca[b][j])
			a = lca[a][j], b= lca[b][j];
	if(a!=b)
		a = lca[a][0], b = lca[b][0];
	return a;
}

#define ch 200

void calcdp(ll hd, ll pr){
	for(auto& hr : g[hd]){
		if(hr == pr){
			continue;
		}
		dp[hr] = dp[hd] + calcval(val[hd], val[hr]);
		calcdp(hr, hd);
	}
}

bool isp(ll pr, ll hd){
	return tin[pr] <= tin[hd] && tout[hd] <= tout[pr];
}

ll findChild(ll pr, ll hd){
	// find child of pr that is in direction of hd
	ll lo = 0, hi = (ll)sorted[pr].size() - 1;
	while(lo < hi){
		ll mid = (lo+hi)/2 + 1;
		ll hr = sorted[pr][mid];
		if(tin[hr] > tin[hd]){
			hi = mid-1;
		}
		else{
			lo = mid;
		}
	}
	return sorted[pr][lo];
}

void deal(){
	ll n , q;
	cin>>n>>q;
	fori(n){
		cin>>val[i];
		valn[i] = val[i];
	}
	fori(n-1){
		ll ai, bi;
		cin>>ai>>bi;
		--ai, --bi;
		g[ai].pb(bi);
		g[bi].pb(ai);
	}
	{
		ll tim = 1;
		dfslca(0, 0, tim);
		pre(n);
		calcdp(0, 0);
	}
	map<ll, ll> dif;
	forl(q){
		ll ty ;
		cin>>ty;
		if(ty == 1){
			ll u, c;
			cin>>u>>c;
			--u;
			dif[u] = c;
			valn[u] = c;
		}
		else{
		//	cout<<149<<endl;
			ll u, v;
			cin>>u>>v;
			--u, --v;
			ll lc = LCA(u, v);
			ll ans = dp[u] + dp[v] - 2*dp[lc];
			unordered_set<ll > again;
			for(auto& el : dif){
		//		cout<<157<<endl;
				ll pr = el.ff;
				ll p1 = isp(pr, u);
				ll p2 = isp(pr, v);
				if(p1 && (!p2 || pr == lc) && pr!=u){
					ll a = pr;
		//			cout<<163<<endl;
					ll b = findChild(pr, u);
		//			cout<<165<<endl;
					if(b < a){
						swap(a, b);
					}
					again.insert(a*MAX + b);
				}
				if(p2 && (!p1 || pr == lc) && pr!=v){
					ll a = pr;
					ll b = findChild(pr, v);
					if(b < a){
						swap(a, b);
					}
					again.insert(a*MAX + b);
				}
				if(lca[pr][0] != pr && ((p1^p2) || (lca[pr][0] == lc && (p1||p2)) )){
					ll a = pr;
					ll b = lca[pr][0];
					if(b < a){
						swap(a, b);
					}
					again.insert(a*MAX + b);
				}
		//		cout<<185<<endl;
			}
			for(auto& el : again){
				ll a = el / MAX , b = el % MAX;
				ans -= calcval(val[a], val[b]);
				ans += calcval(valn[a], valn[b]);
			}
			cout<<ans<<'\n';
		//	cout<<190<<endl;
		}
		if((ll)dif.size() > ch){
			fori(n){
				val[i] = valn[i];
			}
			calcdp(0, 0);
			dif.clear();
		}
	}
}
 

int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}