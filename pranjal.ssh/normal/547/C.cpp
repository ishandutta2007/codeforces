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
#define sz(a) (int((a).size()))
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


const int N=5e5+10;

int a[N];
int f[N];
int sv[N];
vi p[N];
vi yo[N];

int main()
{
    boost;

    sv[1]=1;
    FOR(i,2,707)
    {
        if(sv[i]==0)
            for(int j=i*i;j<=500000;j+=i)
                sv[j]=i;
    }

    int n,q;
    cin>>n>>q;
    FOR(i,1,n)
    {
        cin>>a[i];
        int x=a[i];
        while(x>1)
        {
            int y=sv[x];
            if(y==0)y=x;
            while(x%y==0)
                x/=y;
            p[i].pb(y);
        }
    }
    FOR(i,1,n)
    {
        int aa[1<<sz(p[i])];
        aa[0]=1;
        yo[i].pb(1);
        FOR(j,1,(1<<sz(p[i]))-1)
        {
            aa[j]=aa[j-(j&(-j))]*p[i][int(log2(j&(-j)))];

            if(__builtin_popcount(j)&1)
            yo[i].pb(-aa[j]);
            else yo[i].pb(aa[j]);
        }
        // cout<<a[i]<<": ";
        // tr(yo[i],it)
        // cout<<*it<<" ";cout<<"\n";
    }
    

    ll ans=0;
    while(q--)
    {
        int x;
        cin>>x;
        a[x]=-a[x];
        if(a[x]<0)
        {
            tr(yo[x],it)
            ans+=f[abs(*it)]*((*it)/(abs(*it)));

            tr(yo[x],it)
            f[abs(*it)]++;
        }
        else
        {
            tr(yo[x],it)
            ans-=f[abs(*it)]*((*it)/(abs(*it)));

            if(a[x]==1)
                ans++;
            tr(yo[x],it)
            f[abs(*it)]--;
        }
        cout<<ans<<"\n";
    }

    return 0;
}