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
const ll inf =  2*pow(10,9);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,6) + 10)
////////////////////////////////////////////////////////////////////////////////
// GCC Internal Structures (Rope and BST with rank)
////////////////////////////////////////////////////////////////////////////////
// Rope structure (log time arbitrary rotation, slicing, substr operations)
#include <ext/rope> //header with rope
#include <ext/pb_ds/assoc_container.hpp> // BST stuff
#include <ext/pb_ds/tree_policy.hpp>   // BST stuff
using namespace __gnu_pbds;        // BST namespace
using namespace __gnu_cxx; //namespace with rope and some additional stuff
vector<pair<ll,ll> > que;
ll seen[MAX];
deque<pair<ll, ll> > when;
 typedef tree<ll, ll, less<ll>, rb_tree_tag,  tree_order_statistics_node_update> map_t;
map_t current;
ll ans[MAX];
ll first_time[MAX];
void deal(){
	ll n, m , q;
	cin>>n>>m>>q;
	fori(n){
		ll ed;
		cin>>ed;
		seen[ed]++;
	}
	ll years = n+1;
	ll count_ = 0;
	ll selected = 0;
	for(ll i =1; i<=m ; i++){
		when.pb(mp(seen[i], i));
	}
	sort(when.begin(), when.end());
	fori(when.size()){
		while(count_ < when[i].ff)
			count_++, years+=selected;
		first_time[when[i].ss] = years;
		++selected;
	}
	// output first_times
//	cout<<"we here "<<endl;
	when.clear();
	years = 0;
	for(ll i=1; i<=m; i++){
	//	cerr<<"the guy number "<<i<<" will join at year beginning with "<<first_time[i]<<endl;
		when.pb(mp(first_time[i], i));
	}
	fori(q){
		ll yr;
		cin>>yr;
		que.pb(mp(yr, i));
	}
	sort(que.begin(), que.end());
	sort(when.begin(), when.end());
	years = n+1;
	fori(que.size()){
	//	cerr<<"we at query for year "<<que[i].ff<<endl;
		while(when.size() && years<=que[i].ff){
	//		cout<<"years "<<years<<endl;
			while(when.size() && years == when[0].ff){
	//			cout<<"we inserted "<<when[0].ss<<endl;
				current.insert(mp(when[0].ss, when[0].ss)), when.pop_front();
			}
			years+=current.size();
	//		cout<<"years now "<<years<<endl;
		}
		que[i].ff-=years-current.size();
		ans[que[i].ss] = current.find_by_order((ll)(que[i].ff%(current.size()) ))->ss;
	//	cerr<<"the answer "<<ans[que[i].ss]<<endl;
	}
	fori(q)
		cout<<ans[i]<<'\n';
}

int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}