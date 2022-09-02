#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>


#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define SZ(x) (int)x.size()
#define INF (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define pii pair<int,int>
#define pll pair<i64,i64>
#define pmp make_pair
#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define sds(x) scanf("%s",x)
#define pfi(x) printf("%d\n",x);
#define uu first
#define vv second
using namespace std;
template<class T> inline T sqr(T x){return x*x;}

template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/__gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
    oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
    b.end(), *q ) ) q++;}return oot;
}
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1<<pos))
#define off(n,pos)  n & ~(1<<pos)
#define isOn(n,pos) (bool)(n & (1<<pos))
string toBin(int n){ string s; repv(i,10)s+=(isOn(n,i)+'0');return s;}

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case #%lld: ",++ks);


#define mx 100002
i64 a[mx];
i64 s[mx];

i64 n;
i64 sum(i64 b,i64 e)
{
    if(b>e) return 0;
    if(b>n) return 0;
    if(e>n) e=n;
    if(e>n) e/=0;
    return s[e]-s[b-1];
}
i64 solve(i64 k)
{
    i64 i=2,ans=0,m=1,r=k;
    while(i<=n)
    {
        if(k<0)k/=0;
        i64 b=i;
        i64 e=i+r-1;
        
        ans+=sum(b,e)*m;
        m++;
        r=r*k;
        i=e+1;
        
    }
    if(ans<0) ans/=0;
    return ans;
}
int main(){
    
    //READ("in");
    //freopen("outm","w",stdout);
        cin>>n;
        repl(i,n)
        {
            cin>>a[i];
            
        }
        sort(a+1,a+1+n,greater<i64>());
        repl(i,n)
        s[i]=s[i-1]+a[i];
        i64 q;
        cin>>q;
        
        i64 k1=solve(1);
        vector<i64>out;
        rep(st,q)
        {           
            i64 k;
            cin>>k;
            if(k==1) out.pb(k1);
            else
            out.pb(solve(k));
        }
        if(SZ(out)!=q) q/=0;
        rep(i,SZ(out))cout<<out[i]<<" ";
        puts("");
    
    return 0;
}