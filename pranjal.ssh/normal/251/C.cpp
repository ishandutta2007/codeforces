#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
const int P = 9*8*7*5*11*13;
ll done[P];
ll _ans[P];
int main()
{
  boost;
  memset(done,~0,sizeof done);
  ll a,b;cin>>a>>b;
    int k;cin>>k;
    vll yo;
    FOR(i,0,k-2){yo.pb(i+2);}    
    ll ans=0;
    done[a%P]=a;
    _ans[a%P]=0;
    while(a>b){
      ll mn = a-1;
      for(auto it:yo)
      if(a-a%it>=b)mn=min(mn,a-a%it);
      if(~done[mn%P]){
        ++ans;
        a=mn;
        ll x = done[mn%P]-a;
        ll y =ans- _ans[mn%P];
        ll no = (a-b)/x;
        ans+=y*no;
        a-=no*x;
        break;
      }
      else done[mn%P]=mn,_ans[mn%P]=ans+1;
      a=mn;
      ++ans;
    }
    
    while(a>b){
      ll mn = a-1;
      for(auto it:yo)
      if(a-a%it>=b)mn=min(mn,a-a%it);
      a=mn;
      ++ans;
    }
    cout<<ans;

  return 0;
}