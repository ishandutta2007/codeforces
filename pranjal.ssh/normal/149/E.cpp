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
vi z_function(string s) 
{
    int n = s.length();
    vi z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) 
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
   boost;
  string s;cin>>s;
  string sr = s;reverse(all(sr));
  int n = s.length();
  int m;cin>>m;
  vector<string> yo(m); 
  int ans = 0;

  FOR(i,0,m-1){
    cin>>yo[i];
    if(yo[i].length()==1)continue;
    vi zf = z_function(yo[i]+"#"+s);
    reverse(all(yo[i]));
    vi zr = z_function(yo[i]+"#"+sr);
    vi f(n);vi r(n+n);
    int y = yo[i].length();
    FOR(i,0,n-1)f[i]=zf[i+y+1];
    FOR(i,y+1,n+y)r[n-1-(i+zr[i]-1-y-1)]=max(r[n-1-(i+zr[i]-1-y-1)],zr[i]);
    FOR(i,1,n-1)r[i]=max(r[i],r[i-1]-1);
    NFOR(i,n-2,0)r[i]=max(r[i+1],r[i]);
    
    FOR(i,1,n-1)
      if(f[i-1] and f[i-1]+r[i-1+f[i-1]]>=y)
        {++ans;break;}
  }
  cout<<ans<<"\n";
  return 0;
}