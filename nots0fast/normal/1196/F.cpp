
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
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7  ;
#define ld long double
#define MAX (int)(pow(10,6)+ 10)
#define pq priority_queue

vector<pair<ll,ll> > g[MAX];



struct srt{
	bool operator () (pair<ll,ll>& a, pair<ll,ll> & b){
		if(a.ff!=b.ff)
		return a.ff > b.ff;
		return a.ss > b.ss;
	}
};

vector< ll > overall;
ll idx[MAX];
void run_floyd(vector<ll>& bfs){
	ll n = bfs.size();
	vector<vector<ll> > dist(n,vector<ll> (n, inf));
	fori(n)
		dist[i][i] = 0;
	fori(bfs.size()){
		ll hd = bfs[i];
		ll act = idx[hd];
		for(auto el : g[hd]){
			ll act2 = idx[el.ff];
			ll cs = el.ss;
			dist[act][act2] = min(dist[act][act2] ,cs);
			dist[act2][act] = min(dist[act2][act] ,cs);
		}
	}
	forj(n)
		fori(n)
			fork(n)
				dist[i][k] = min(dist[i][k], dist[i][j]+dist[j][k]);
	fori(n)
		forj(i)
			overall.pb(dist[i][j]);
}



namespace dsu{
	ll aid[MAX];
	vector<ll> dsu[MAX];
	void ini(ll n){
		fori(n)
			aid[i] = i, dsu[i].clear(), dsu[i].push_back(i);
	}
	bool join(ll a,ll b){  //	1 - if joined, 0 - if they were already joined 
		ll aid1 = aid[a], aid2 = aid[b];
		if(dsu[aid2].size() > dsu[aid1].size())
			swap(aid1,aid2);
		if(aid1==aid2)
			return 0;
		for(auto hd : dsu[aid2]){
			aid[hd] = aid1;
			dsu[aid1].push_back(hd);
		}
		dsu[aid2].clear();
		return 1;
	}
};
void deal(){
	ll n , m , k;
	cin>>n>>m>>k;
	vector<vector<ll> > edg;
	fori(m){
		ll a, b, c;
		cin>>a>>b>>c;
		--a, --b;
		edg.pb(vector<ll>({c,b,a}));
	}
	sort(edg.begin(), edg.end());
	ll ans = 1;
	dsu::ini(n);
	fori(m){
		ans+=dsu::join(edg[i][1], edg[i][2]);
		g[edg[i][1]].pb(mp(edg[i][2],edg[i][0]));
		g[edg[i][2]].pb(mp(edg[i][1],edg[i][0]));
		if(ans >= 500)
			break;
	}
	vector<bool> vis(n,0);
	fori(n){
		if(!vis[i]){
			vector<ll> bfs(1,i);
			forj(bfs.size()){
				ll hd = bfs[j];
				idx[hd] = j;
				for(auto el : g[hd]){
					ll hr = el.ff;
					if(!vis[hr])
						vis[hr] = 1, bfs.pb(hr);
				}
			}
			run_floyd(bfs);
		}
	}
	sort(overall.begin(), overall.end());
	cout<<overall[k-1];
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
/*
 
5 1
1 2 3 4 5


*/