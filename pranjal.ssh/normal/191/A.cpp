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



int dp[26][26];
vector<string> s;
vi l;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    s.rz(n);
    l.rz(n);
    FOR(i,0,n-1)cin>>s[i],l[i]=s[i].length();
    FOR(i,0,25)FOR(j,0,25)dp[i][j]=-INF;
    FOR(i,0,n-1)
    {
        FOR(j,0,25)
        {
            dp[j][s[i][l[i]-1]-'a']=max(dp[j][s[i][l[i]-1]-'a'],dp[j][s[i][0]-'a']+l[i]);
        }
        dp[s[i][0]-'a'][s[i][l[i]-1]-'a']=max(dp[s[i][0]-'a'][s[i][l[i]-1]-'a'],l[i]);
    }
    int ans=0;
    FOR(i,0,25)ans=max(ans,dp[i][i]);
    cout<<ans;
    
    return 0;
}