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
#define PI 2*acos(0)
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 2*pow(10,9)+10;
const ll inf =  pow(10,18);
ll modulo = 163577857;
////////////////////////////////////////////////////////////////////////////////
// GCC Internal Structures (Rope and BST with rank)
////////////////////////////////////////////////////////////////////////////////
// Rope structure (log time arbitrary rotation, slicing, substr operations)
#include <ext/rope> //header with rope
#include <ext/pb_ds/assoc_container.hpp> // BST stuff
#include <ext/pb_ds/tree_policy.hpp>   // BST stuff
using namespace __gnu_pbds;        // BST namespace
using namespace __gnu_cxx; //namespace with rope and some additional stuff
#define MAX 400100
 
ll arr[MAX][2];
ll dif[2]; 	// the number of different 0 - xs, 1 - ys
 
void fx(ll n){
	forj(2){
		map<ll, ll> all;
		fori(n)
			all[arr[i][j]] = 1;
		auto it = all.begin();
		ll index = 0;
		while(it!= all.end()){
			(*it).ss = index;
			++index;
			++it;
		}
		dif[j] = index;
		fori(n)
			arr[i][j] = all[arr[i][j]];
	}
}
 
vector<ll> all[MAX]; // all the "x"s related to current "y"
 
 
void deal(){
	ll n;
	cin>>n;
	fori(n)
		forj(2)
			cin>>arr[i][j];
	fx(n);
	fori(n)	
		all[arr[i][1]].pb(arr[i][0]);
	rope<ll> cur;
	ll ans = 0;
	for(ll y = dif[1] - 1; y>-1; y--){
//		cout<<"now at y: "<<y<<endl;
		vector<ll> now;
		for(auto x : all[y])
			now.pb(x);
		sort(now.begin(), now.end());
		ll pv = 0; // start for the next insertion
		ll add = 0;
		fori(now.size()){
			ll elem = now[i];
			ll lo = pv, hi  = cur.size();
			while(lo<hi){
				ll mid = (lo+hi)>>1;
				if(cur[mid] < now[i])
					lo =  mid+1;
				else
					hi = mid;
			}
			add-=(lo-pv)*(lo-pv+1)/2;
//			cout<<"we subtractin "<<(lo-pv)*(lo-pv+1)/2<<endl;
			if(lo==cur.size() || cur[lo] != now[i])
				cur.insert(lo, now[i]);
//			cout<<"size: "<<cur.size()<<" we inserting it to "<<lo<<endl;
			pv = lo+1;
		}
		add-=((ll)cur.size() - pv)*((ll)cur.size()-pv+1)/2;
		add+=((ll)cur.size())*((ll)cur.size()+1)/2;
//		cout<<"in the end we adding "<<add<<endl;
		ans+=add;
	}
	cout<<ans;
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}
 
 
 
 
 

/*
6
1 3
2 2
2 4
3 3
3 8
10 10
*/