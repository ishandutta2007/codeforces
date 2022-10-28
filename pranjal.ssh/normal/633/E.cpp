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

int dpv[22][1000010];
int dpc[22][1000010];

int lg2[1000010];
vi v,c,p;

inline int rmqv(int l, int r)
{
    int j=lg2[r-l+1];
    return v[dpv[j][l]]>v[dpv[j][r-(1<<j)+1]] ? v[dpv[j][l]] : v[dpv[j][r-(1<<j)+1]];
}
void PREV(int n)
{
    FOR(i,0,n-1)    dpv[0][i]=i;
    for(int j=1;(1<<j)<=n;++j){
        for(int i=0; i+ (1<<j)<=n; ++i){
            dpv[j][i]= dpv[j-1][i];
            if((v[dpv[j-1][i]] < v[dpv[j-1][i+(1<<(j-1))]]))
              dpv[j][i]= dpv[j-1][i + (1<<(j-1))];
        }
    }
}   

inline int rmqc(int l, int r)
{
    int j=lg2[r-l+1];
    return c[dpc[j][l]]<c[dpc[j][r-(1<<j)+1]] ? c[dpc[j][l]] : c[dpc[j][r-(1<<j)+1]];
}
void prec(int n)
{
    FOR(i,0,n-1)    dpc[0][i]=i;
    for(int j=1;(1<<j)<=n;++j){
        for(int i=0; i+ (1<<j)<=n; ++i){
            dpc[j][i]= dpc[j-1][i];
            if((c[dpc[j-1][i]] > c[dpc[j-1][i+(1<<(j-1))]]))
              dpc[j][i]= dpc[j-1][i + (1<<(j-1))];
        }
    }
}   








int main()
{
    boost;
    int n,k;
    cin>>n>>k;
    lg2[1]=0;
    FOR(i,2,1000000)lg2[i]=lg2[i-1]+((i&(i-1))==0);

    v.rz(n);c.rz(n);p.rz(n);
    FOR(i,0,n-1)cin>>v[i];
    FOR(i,0,n-1)cin>>c[i];

    PREV(n);
    prec(n);

    FOR(i,0,n-1)
    {
      int st=i,en=n-1;
      int mid;
      while(1)
      {
        mid=(st+en)>>1;
        if(st==en)break;
        int x=100*rmqv(i,mid)-rmqc(i,mid);
        if(x>0)
          en=mid;
        else
          st=mid+1;
      }
      p[i]=max(p[i],min(100*rmqv(i,mid),rmqc(i,mid)));
      if(mid>i)
      --mid,p[i]=max(p[i],min(100*rmqv(i,mid),rmqc(i,mid)));

    
    }

    sort(all(p));
    double ans=0;
    double temp=1;
    FOR(i,1,n-k+1)
    {
      if(i>1)
      temp*=(n-k-(i-2));
      temp/=(n-(i-1));
      ans+=temp*p[i-1];
    }
    cout<<fixed<<setprecision(9)<<ans*k;

	return 0;
}