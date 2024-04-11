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
int pp[5000][5000];
string s;
int p(int l, int r)
{
    int &ans=pp[l][r];
    if(ans!=-1)return ans;
    
    if(l==r) return ans=1;
    if(l+1==r)return ans=(s[l]==s[r]);
    
     return ans=(s[l]==s[r] and p(l+1,r-1));
}
int f(int l, int r)
{
    int &ans=dp[l][r];
    if(ans!=0)return ans;
    
    if(l==r) return ans=1;
    if(l+1==r)return ans=2+(s[l]==s[r]);
    
     return ans=f(l+1,r)+f(l,r-1)-f(l+1,r-1)+p(l,r);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>s;
    int q;
    cin>>q;
    memset(pp,-1,sizeof(pp));
    while(q--)
    {
        int i, j;
        cin>>i>>j;
        cout<<f(i-1,j-1)<<"\n";
    }
    
    return 0;
}