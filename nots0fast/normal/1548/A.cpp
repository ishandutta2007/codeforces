#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision
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
#define ld long double
#define pb(a) push_back(a)
#define mt make_tuple
ll inf = 1e18;
ll INF = pow(10,9);
ll modulo = 998244353;
double eps = 1e-10;



void deal(){
      ll n, m;
      cin>>n>>m;
      ll ans = 0;
      vector<set<ll> > val(n);
      fori(m){
            ll ui, vi;
            cin>>ui>>vi;
            --ui, --vi;
            if(vi < ui){
                  swap(ui, vi);
            }
            val[ui].insert(vi);
      }
      fori(n){
            if(val[i].empty()){
                  ++ans;
            }
      }
      ll q;
      cin>>q;
      forl(q){
            ll ty;
            cin>>ty;
            if(ty == 1){
                  ll ai, bi;
                  cin>>ai>>bi;
                  --ai, --bi;
                  if(ai > bi){
                        swap(ai, bi);
                  }
                  if(val[ai].empty()){
                        --ans;
                  }
                  val[ai].insert(bi);
            }
            else if(ty == 2){
                  ll ai, bi;
                  cin>>ai>>bi;
                  --ai, --bi;
                  if(ai > bi){
                        swap(ai, bi);
                  }
                  val[ai].erase(bi);
                  if(val[ai].empty()){
                        ++ans;
                  }
            }
            else{
                  cout<<ans<<'\n';
            }
      }
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	deal();
}