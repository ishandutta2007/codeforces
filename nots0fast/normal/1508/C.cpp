#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define ll long long 
#define double long double
#define MAX (int)(2*pow(10,5) + 10)
#define MAX2 (int)20
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = pow(10,9) + 7;
double eps = 1e-10;
ifstream in;
ofstream out;
 
vector<int> g[MAX];
int lca[MAX][MAX2];
int mnw[MAX][MAX2];
ll wei[MAX];
ll dep[MAX];
 
 
void dfs(ll hd, ll pr){
	lca[hd][0] = pr;
	mnw[hd][0] = wei[hd];
	for(auto hr : g[hd]){
		if(hr == pr)
			continue;
		dep[hr ] = dep[hd]+ 1; 
		dfs(hr, hd);
	}
}
 
void pre(ll n){
	for(ll j = 1; j<MAX2; j++){
		fori(n){
			lca[i][j]=  lca[lca[i][j-1]][j-1];
			mnw[i][j] = min(mnw[i][j-1], mnw[lca[i][j-1]][j-1]);
		}
	}
}
 
ll minBetween(ll a, ll b){
	int ans = (1<<30);
	if(dep[a] < dep[b])
		swap(a,b);
	// a is deeper now, swim a upwards
	for(ll j = MAX2-1; j>-1; j--)
		if(dep[lca[a][j]] > dep[b])
			ans = min(ans, mnw[a][j]), a = lca[a][j];
	if(dep[a] != dep[b])
		 ans = min(ans, mnw[a][0]), a = lca[a][0];
	for(ll j=MAX2-1; j>-1; j--)
		if(lca[a][j]!=lca[b][j])
			ans = min(ans, mnw[a][j]), ans = min(ans, mnw[b][j]), a = lca[a][j], b= lca[b][j];
	if(a!=b)
		ans = min(ans, mnw[a][0]), ans = min(ans, mnw[b][0]), a = lca[a][0], b = lca[b][0];
	return ans;
}
	
void deal(){
	// !!! call dfs(root, root) , dont put -1 as the parent of the root !!!
	// and then call pre() 
	
	ll n , m;
	cin>>n>>m;
	
	// Prim's
	
	vector<map<ll,ll> >  gr(n);
	
	ll xorAll = 0;
	
	fori(m){
		ll ui, vi, ci;
		cin>>ui>>vi>>ci;
		--ui, --vi;
		
		gr[ui][vi] = ci;
		gr[vi][ui] = ci;
		xorAll ^= ci;
	}
	
	set<ll> notSeen;
	fori(n){
		notSeen.insert(i);
	}
	
	priority_queue<vector<ll> , vector<vector<ll> >, greater<vector<ll>> > pq;	// cost, where from , where to
	pq.push(vector<ll>({0,0,0}));
	notSeen.erase(0);
	
	vector<bool> expanded(n,0);
	
	map<ll,map<ll,ll> > taken;
	
	ll mst = 0;
	
	ll used = 0;
	
	while(pq.size()){
		auto cur = pq.top();
		pq.pop();
		ll hd = cur[1];
		
		if(expanded[hd]){
			continue;
		}
		
//		cout<<"we at "<<cur[1]<<" came from "<<cur[2]<<" with cost "<<cur[0]<<endl;
		
		expanded[hd] = 1;
		
		
		if(hd!= 0){
			wei[hd] = cur[0];
			g[cur[2]].pb(cur[1]);
			
			mst+=cur[0];
			
			if(!cur[0]){
				++used;
			}
			else{
				taken[cur[1]][cur[2]] = 1;
				taken[cur[2]][cur[1]] = 1;
			}
		}
		
		vector<ll> toErase;
		
		for(auto& el : notSeen){
//			cout<<"we checking "<<el<<endl;
			if(gr[hd].find(el) == gr[hd].end()){
//				cout<<el<<" is good "<<endl;
				toErase.pb(el);
				pq.push(vector<ll>({0, el, hd}));
			}
		}
		
		for(auto& el : toErase){
			notSeen.erase(el);
		}
		
		for(auto& el : gr[hd]){
			pq.push(vector<ll>({el.ss, el.ff, hd}));
		}
		
	}
	
	
//	cout<<"we used "<<used<<" 0 edges "<<endl;
	
	ll can = n*(n-1)/2 - m;
	
	if(used < can){
		cout<<mst<<'\n';
		return;
	}
	
	
	dfs(0,0);
	pre(n);
	
	ll minEdge = xorAll;
	
	fori(n){
		for(auto& el : gr[i]){
			ll hr = el.ff;
			ll cost = el.ss;
			ll hd = i;
			if(!taken[hd][hr]){
				ll mn = minBetween(hd, hr);
				
			//	cout<<"min between "<<hd+1<<" and "<<hr+1<<" is "<<mn<<endl;
				
				if(mn == 0 ){
					minEdge = min(minEdge, cost);
				}
			}
		}
	}
	
	mst += minEdge;
	
	cout<<mst;
	
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();  // check whether lca of two nodes is the same
}