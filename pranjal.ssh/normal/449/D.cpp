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


int a[1000001];
int dp[21][2000001];
int expo(int base, int exp) {
    int res=1;
    while(exp>0) {
       if(exp&1) res=mul(res,base);
       base=mul(base,base);
       exp=exp>>1;
    }
    return res;
}
int main()
{
    boost;
    int n;
    cin>>n;
    FOR(i,1,n)cin>>a[i],dp[0][a[i]]++;
    FOR(i,1,20)
    {
        FOR(j,0,1000000)
        {
            if(j&(1<<(i-1)))
            {
                dp[i][j]=dp[i-1][j];
            }
            else
                dp[i][j]=add(dp[i-1][j],dp[i-1][j|(1<<(i-1))]);
        }
    }
    int ans=0;
    FOR(i,0,(1<<20)-1)
    {
        int x=__builtin_popcount(i);
        x&=1;
        if(x)
            ans=add(ans,INF-expo(2,dp[20][i]));
        else ans=add(ans,expo(2,dp[20][i]));
    }
    cout<<ans;
    return 0;
}