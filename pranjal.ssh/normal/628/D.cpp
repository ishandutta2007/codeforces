// Flow credits : https://web.stanford.edu/~liszt90/acm/notebook.html

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
inline int mul(int a,int b, int m=INF){return (a*b)%m;}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}


int dp[2001][2001][2];
int m,d;
int p[2001];
string a,b;
int kar(string t)
{
    int n = t.length();
    int ans=0;
    int off=0;
    
    int i=0;
    for(i=0;i<=n-1;++i)
    {
        if(i&1)
        {
            if(d<=t[i]-'0'-1)
            {
                ans=add(ans,dp[n-1-i][((m-p[n-1-i])*(d)-off+m)%m][0]);
                
                break;
            }
            else if (d==t[i]-'0')
            off=(off+(t[i]-'0')*p[n-1-i])%m;
            else
              { break;}
            continue;
        }
        FOR(j,0,t[i]-'0'-1)
        {
            if(j!=d)
            ans=add(ans,dp[n-1-i][((m-p[n-1-i])*(j)-off+m)%m][1]);
        }
        off=(off+(t[i]-'0')*p[n-1-i])%m;
        if(t[i]-'0'==d)
            break;

    }
    return add(ans,(off==0) and (i==n));
}

int main()
{
    boost;
    // memset(dp,-1,sizeof dp);
    p[0]=1;
    cin>>m>>d;
    
    cin>>a>>b;
    FOR(i,1,2000)p[i]=(p[i-1]*10)%m;

    dp[0][0][0]=dp[0][0][1]=1;

    // FOR(l,0,9)
    // {
    //     if(l==d)
    //         dp[1][l%m][1]=1;
    //     else
    //         dp[1][l%m][0]++;
    // }
    int n =a.length();
    FOR(i,1,n)
    {
        FOR(j,0,m-1)
        {
            FOR(k,0,1)
            {
                if(k^1)
                {
                    FOR(l,0,9)
                    if(l!=d)
                    dp[i][j][k]=add(dp[i][j][k],dp[i-1][((-p[i-1]+m)*l+j)%m][k^1]);
                }   
                else
                {
                    FOR(l,d,d)
                    dp[i][j][k]=add(dp[i][j][k],dp[i-1][((-p[i-1]+m)*l+j)%m][k^1]);
                }
            }
        }
    }
    
    
    
    int ans=add(kar(b),INF-kar(a));
    bool good=1;
    int x=0;
    
    FOR(i,0,n-1)
    {
        x=(x*10+a[i]-'0')%m;
        if(i&1)
        {
            good&=(a[i]-'0'==d);
        }
        else
        good&=(a[i]-'0'!=d);
    }
    good&=(x==0);
    
    cout<<add(ans,good);
    return 0;
}