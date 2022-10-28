#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define ufy(v) sort(all(v));(v).erase(unique(all((v))),(v).end())
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}

vi a;
struct frac
{
    ll n,d;
    bool operator<(const frac &that){return (n*that.d) < (d*that.n);}
};
vll sum;

int main()
{
    boost;
    int n;cin>>n;a.rz(n);sum.rz(n+1);
    FOR(i,0,n-1)cin>>a[i];
    sort(all(a));
    FOR(i,1,n)sum[i]=sum[i-1]+a[i-1];

    frac mx={-1,1};
    ii ans={-1,-1};
    FOR(i,0,n-1)
    {
        int st=0,en=min(i,n-i-1);
        int m1,m2;
        while(en-st>=4)
        {
            m1=(2*st+en)/3;
            m2=(st+2*en)/3;
            frac M1={sum[n]-sum[n-m1] + sum[i+1] - sum[i-m1]   ,2*m1+1};
            frac M2={sum[n]-sum[n-m2] + sum[i+1] - sum[i-m2]   ,2*m2+1};
            if(M1<M2)   
                st=m1;
            else
                en=m2;
        }
        FOR(j,st,en)
        {
            frac t={sum[n]-sum[n-j] + sum[i+1] - sum[i-j] -(2*j+1LL)*a[i]  ,2*j+1};
            if(mx<t)
                mx=t,ans={i,j};
        }
    }
    cout<<2*ans.S+1<<"\n";
    FOR(i,0,ans.S)
        cout<<a[ans.F-i]<<" ";
    FOR(i,0,ans.S-1)
    cout<<a[n-1-i]<<" ";

    return 0;
}