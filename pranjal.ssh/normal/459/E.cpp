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
typedef pair<int,ii> iii;
typedef vector<iii> viii;

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



vvi g;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    viii e;
    FOR(i,0,m-1){int a,b,c;cin>>a>>b>>c;e.pb({c,{a,b}});}
    sort(all(e));
    vi dp(n+1);
    vi tp(n+1);
    FOR(i,0,m-1)
    {
        int j=i;
        tp[e[i].S.S]=max(tp[e[i].S.S],dp[e[i].S.F]+1);
        while(i!=m-1 && e[i+1].F==e[i].F)
        {
            ++i;
            tp[e[i].S.S]=max(tp[e[i].S.S],dp[e[i].S.F]+1);
        }
        FOR(k,j,i)dp[e[k].S.S]=max(dp[e[k].S.S],tp[e[k].S.S]);
        FOR(k,j,i)tp[e[k].S.S]=0;
        
    }
    int ans=0;
    FOR(i,1,n)ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}