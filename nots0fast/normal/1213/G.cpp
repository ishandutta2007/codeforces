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
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10,18);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,6) + 10)


namespace dsu{
	int aid[MAX];
	vector<int> dsu[MAX];
	ll sum = 0;
	void ini(int n){
		fori(n)
			aid[i] = i, dsu[i].clear(), dsu[i].push_back(i);
	}
	bool join(int a,int b){  //	1 - if joined, 0 - if they were already joined 
		int aid1 = aid[a], aid2 = aid[b];
		if(dsu[aid2].size() > dsu[aid1].size())
			swap(aid1,aid2);
		if(aid1==aid2)
			return 0;
		sum+=(ll)dsu[aid1].size() * (ll)dsu[aid2].size();
		for(auto hd : dsu[aid2]){
			aid[hd] = aid1;
			dsu[aid1].push_back(hd);
		}
		dsu[aid2].clear();
		return 1;
	}
};

void deal(){
	ll n , m;
	cin>>n>>m;
	vector<vector<ll> > edg;
	dsu::ini(n);
	fori(n-1){
		ll u,v,ed;
		cin>>u>>v>>ed;
		--u, -- v;
		edg.pb(vector<ll> ({ed, u, v}));
	}
	sort(edg.begin(), edg.end());
	vector<pair<ll,ll> > all;
	fori(n-1){
		ll u  = edg[i][1], v = edg[i][2];
		dsu::join(u,v);
		all.pb(mp(edg[i][0], dsu::sum));
	}
	all.pb(mp(inf, -1));
	fori(m){
		ll q;
		cin>>q;
		auto it = upper_bound(all.begin(), all.end(), mp(q, inf));
		if(it == all.begin())
			cout<<"0 ";
		else
			cout<<(*(--it)).ss<<' ';
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}