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
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
const ll modulo = pow(10,9) + 7;

#include <ext/pb_ds/assoc_container.hpp> // BST stuff /// keep-include
#include <ext/pb_ds/tree_policy.hpp>   // BST stuff   /// keep-include
using namespace __gnu_pbds;        // BST namespace
template <typename T> using ordered_set = tree<T, null_type, less<T>,
				 rb_tree_tag, tree_order_statistics_node_update>;

#include <ext/rope> //header with rope                /// keep-include
using namespace __gnu_cxx; //namespace with rope and additional stuff
void example() {
  // rope stuff!
  rope <int> v;                            // initialization
  int i = 10; v.push_back(i);              // adding values
  int l = 0, r = 0;
  rope <int> cur = v.substr(l, r - l + 1); // getting substrings
  v.erase(l, r - l + 1);           // erasing substrings
  v.insert(v.mutable_begin(), cur);    // inserting
  int x = v[i];              // random access

  typedef tree<double, int, less<double>, rb_tree_tag,
      tree_order_statistics_node_update> map_t;
  map_t s;
  s.insert(make_pair(12, 1012));
  s.insert(make_pair(505, 1505));
  s.insert(make_pair(30, 1030));
  cout << s.find_by_order(1)->second << '\n'; // returns kth item
  cout << s.order_of_key(12) << '\n'; // returns count of how many < 12

  gp_hash_table<int, int> h; // faster hash table
  h[x] = 5;
}

typedef tree<ll, ll, less<ll>, rb_tree_tag,
      tree_order_statistics_node_update> map_t;

#define MAX 1'000'010

pair<ll,ll> edges[MAX];
map_t g[MAX];
map_t all;
ll wei[MAX];

ll getsect(ll a, ll b){
	if(edges[a].ff == edges[b].ff || edges[a].ff == edges[b].ss){
		return edges[a].ff;
	}
	if(edges[a].ss == edges[b].ff || edges[a].ss == edges[b].ss){
		return edges[a].ss;
	}
	return -1;
}

bool sect(ll a, ll b){
	if(edges[a].ff == edges[b].ff || edges[a].ff == edges[b].ss){
		return 1;
	}
	if(edges[a].ss == edges[b].ff || edges[a].ss == edges[b].ss){
		return 1;
	}
	return 0;
}

ll getsum(){
	auto it = all.begin();
	vector<ll> four;
	fori(4){
		four.pb((*it).ss);
		++it;
	}
	ll a = four[0], b = four[1], c = four[2];
	if(sect(a, b)){
		if(sect(a, c)){
			ll mn = inf;
	//		cout<<99<<endl;
			{
				ll au = edges[a].ff, av = edges[a].ss;
				ll s1 = (ll)g[au].size() + (ll)g[av].size() - 1;
				if((ll)all.size() > s1){
					ll lo = wei[a], hi = inf;
					while(lo < hi){
						ll mid = (lo + hi)/2;
						ll cnt1 = g[au].order_of_key(mid+1)
								+ g[av].order_of_key(mid+1)
								- 1;
						ll cnt2 = all.order_of_key(mid+1);
						if(cnt2 > cnt1){
							hi = mid;
						}
						else{
							lo = mid+1;
						}
					}
					mn = min(mn, wei[a] + lo);
				}
			}
	//		cout<<120<<endl;
			while(it!=all.end() && four.size() < 6 && sect(a, (*it).ss)){
				four.pb((*it).ss);
				++it;
			}
	//		cout<<126<<endl;
			vector<ll> nds;
			set<ll> tr;
			fori((ll)four.size()){
				ll cr = four[i];
				ll u = edges[cr].ff, v = edges[cr].ss;
				tr.insert(u), tr.insert(v);
			}
			for(auto& el : tr){
				nds.pb(el);
			}
			ll num = nds.size();
			vector<vector<ll> > dt(num, vector<ll>(num, inf));
			fori((ll)four.size()){
				ll cr = four[i];
				ll u = edges[cr].ff, v = edges[cr].ss;
				u = lower_bound(nds.begin(), nds.end(), u) - nds.begin();
				v = lower_bound(nds.begin(), nds.end(), v) - nds.begin();
				dt[u][v] = wei[cr];
				dt[v][u] = wei[cr];
			}
			forj(num){
				fori(num){
					fork(num){
						if(dt[i][j] + dt[j][k] < dt[i][k]){
							dt[i][k] = dt[i][j] + dt[j][k];
						}
					}
				}
			}
	//		cout<<156<<endl;
			fori(num){
				for(ll j = i+1; j<num; j++){
					fork(num){
						if(k == i || k == j){
							continue;
						}
						for(ll l = k+1; l<num; l++){
							if(l == j || l == i){
								continue;
							}
							mn = min(mn, dt[i][j] + dt[k][l]);
						}
					}
				}
			}
	//		cout<<172<<endl;
			return mn;
		}
		else{
			return wei[a] + wei[c];
		}
	}
	else{
		return wei[a] + wei[b];
	}
}

map<ll,map<ll,ll> > tr;

void deal(){
	ll n, m;
	cin>>n>>m;
	fori(m){
		ll a,b, w;
		cin>>a>>b>>w;
		w*=MAX;
		w+=i;
		g[a].insert(mp(w , i));
		g[b].insert(mp(w , i));
		all.insert(mp(w, i));
		edges[i] = mp(a, b);
		wei[i] = w;
		tr[a][b] = i;
		tr[b][a] = i;
	}
	cout<<getsum()/MAX<<'\n';
	ll q;
	cin>>q;
	forl(q){
		ll ty;
		cin>>ty;
		if(ty == 0){
			ll u, v;
			cin>>u>>v;
			ll wh = tr[u][v];
			g[u].erase(wei[wh]);
			g[v].erase(wei[wh]);
			all.erase(wei[wh]);
		}
		else{
			ll v, u, w;
			cin>>u>>v>>w;
			w*=MAX;
			w+=m+l;
			
			g[u].insert(mp(w , l+m));
			g[v].insert(mp(w , l+m));
			all.insert(mp(w, l+m));
			edges[l+m] = mp(u,v);
			wei[l+m] = w;
			tr[u][v] = m+l;
			tr[v][u] = m+l;
		}
		cout<<getsum()/MAX<<'\n';
	}
	
	
}
 
int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}