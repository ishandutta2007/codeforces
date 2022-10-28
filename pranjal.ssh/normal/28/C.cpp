#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

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

double p[51][51][51];
double c[51][51];
int a[51];
double f(int n, int m,int mx)
{
    if(m==0)
    return n==0?mx:0;
    
    double &ans=p[n][m][mx];
    if(ans>-1)return ans;
    int here=0;
    ans=0;
    FOR(i,0,n)
    {
        here=(int)(ceil((i+(double).0)/a[m])+0.5);
        if(m!=1)ans+=c[n][i]*pow((1.0/m),(double)i)*pow((m-(double)1.0)/m,n-i)*f(n-i,m-1,max(here,mx));
        else ans+=c[n][i]*pow((1.0/m),(double)i)*(n-i==0)*f(n-i,m-1,max(here,mx));
    }
    return ans;
}
int main()
{
    boost;
    int n,m;
    cin>>n>>m;
    FOR(i,1,m)cin>>a[i];
    c[0][0]=1;
    C(p,-1);
    
    FOR(i,1,50)
    {
        c[i][0]=1;
        FOR(j,1,i)
        c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    
    cout<<setprecision(20)<<f(n,m,0);
    return 0;
}