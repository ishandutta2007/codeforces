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


string s[501];
int d1[501][501];
int d2[501][501];
int x[501][501];
inline int qry1(int r1,int r2,int c1,int c2)
{
    if(r1>r2 or c1>c2)return 0;
    return d1[r2][c2]-d1[r1-1][c2]-d1[r2][c1-1]+d1[r1-1][c1-1];
}
inline int qry2(int r1,int r2,int c1,int c2)
{
    if(r1>r2 or c1>c2)return 0;
    return d2[r2][c2]-d2[r1-1][c2]-d2[r2][c1-1]+d2[r1-1][c1-1];
}
int main()
{
    boost;
    int h,w;
    cin>>h>>w;
    FOR(i,1,h)cin>>s[i];
    FOR(i,1,h)FOR(j,1,w)x[i][j]=(s[i][j-1]=='.');
    FOR(i,1,h)
    {
        FOR(j,2,w)
        {
            if(x[i][j-1] and x[i][j]) d1[i][j]=1;
        }
    }
    FOR(i,2,h)
    {
        FOR(j,1,w)
        {
            if(x[i-1][j] and x[i][j]) d2[i][j]=1;
        }
    }
    FOR(i,1,h)FOR(j,1,w)d1[i][j]=d1[i-1][j]+d1[i][j-1]-d1[i-1][j-1]+(x[i][j-1] and x[i][j]);
    FOR(i,1,h)FOR(j,1,w)d2[i][j]=d2[i-1][j]+d2[i][j-1]-d2[i-1][j-1]+(x[i-1][j] and x[i][j]);
    int q;
    cin>>q;
    while(q--)
    {
        int r1,r2,c1,c2;
        cin>>r1>>c1>>r2>>c2;
        int ans=qry1(r1,r2,c1+1,c2)+qry2(r1+1,r2,c1,c2);cout<<ans<<"\n";
    }
    return 0;
}