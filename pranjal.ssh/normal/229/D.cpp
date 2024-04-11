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

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define ntr(x,it) for(auto it = x.rbegin();it!=x.rend();++it)
#define sz(a) int((a).size()) 
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

int a[5002];
int dp[5002][5002];
int ss[5002];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    FOR(i,1,n)cin>>a[i],ss[i]=ss[i-1]+a[i];
    FOR(i,0,n)FOR(j,0,n)dp[i][j]=INF;
    FOR(i,0,n)dp[0][i]=0;
    dp[1][1]=0;
       
    FOR(i,2,n)
    {
        int now=0;
        NFOR(j,i,1)
        {
            now+=a[j];
            int p=lower_bound(ss,ss+j-1,ss[j-1]-now)-ss+1;
            dp[i][j]=min(dp[i][min(i,j+1)],dp[j-1][p]+i-j);
        }
    }
    // FOR(i,1,n)
    // {
    //  FOR(j,1,n)
    //  cout<<dp[i][j]<<" ";
    //  cout<<endl;
    // }
    cout<<*min_element(dp[n]+1,dp[n]+n+1);
    return 0;
}