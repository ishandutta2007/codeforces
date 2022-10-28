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

int a[5][2000];
int pos[5][2000];
int dp[2000];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n,k;
    cin>>n>>k;
    
    FOR(i,0,k-1)FOR(j,0,n-1)cin>>a[i][j],a[i][j]--,pos[i][a[i][j]]=j;
    
    dp[0]=1;
    FOR(i,1,n-1)
    {
        dp[i]=1;
        FOR(j,0,i-1)
        {
            bool can=1;
            FOR(l,1,k-1)can&=(pos[l][a[0][i]]>pos[l][a[0][j]]);
            if(can)dp[i]=max(dp[i],dp[j]+1);
        }
    }
    FOR(i,0,n-1)dp[0]=max(dp[0],dp[i]);
    cout<<dp[0];
    return 0;
}