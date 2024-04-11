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
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)

int dp[5000][5000];
//int cum[5000][5000];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    string s;
    cin>>s;
    string t;
    cin>>t;
    int n=s.length();
    int N=t.length();
    
    FOR(i,0,N-1)dp[0][i]=(s[0]==t[i]);
    FOR(i,0,n-1)dp[i][0]=(s[i]==t[0]);
    
    FOR(j,1,N-1)dp[0][j]+=dp[0][j-1];
    
    
    FOR(i,1,n-1)
    {
        FOR(j,1,N-1)
        {
            if(s[i]==t[j])
            {
                dp[i][j]=1+dp[i-1][j-1];
                if(dp[i][j]>=INF)dp[i][j]-=INF;
            }
            dp[i][j]+=dp[i][j-1];
            if(dp[i][j]>=INF)dp[i][j]-=INF;
        }
    }
    
    int ans=0;
    FOR(i,0,n-1){ans+=dp[i][N-1];if(ans>=INF)ans-=INF;}
    cout<<ans;
    return 0;
}