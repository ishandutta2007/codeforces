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



int a[1000001];
map<char,int> mp;
int pos[2000002];
int dp[1000001];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    mp['(']=1;
    mp[')']=-1;
    string s;
    cin>>s;
    int n=s.length();
    FOR(i,1,n)a[i]=a[i-1]+mp[s[i-1]];
    memset(pos,-1,sizeof(pos));
    pos[0+1000000]=0;
    FOR(i,1,n)
    {
        if(s[i-1]==')')
        {
            if(pos[a[i]+1000000]!=-1)
            dp[i]=dp[pos[a[i]+1000000]]+i-pos[a[i]+1000000];
        }
        pos[a[i]+1000000]=i;
    }
    int len=0;
    FOR(i,1,n)len=max(len,dp[i]);
    int x=0;
    FOR(i,1,n)if(dp[i]==len)++x;
    if(len==0)x=1;
    cout<<len<<" "<<x;
    return 0;
}