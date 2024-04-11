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

#define pos(x) (lower_bound(all(pts),x)-pts.begin())
vi pts;
vector<pair<ii,ii>> seg;

vector<pair<int,ii>> ss;

struct BIT1
{
    vector<long long> t;
    long long n;
    BIT1()
    {
            n=0;
            t.clear();
    }
    BIT1(long long sz)
    {
        n=sz;
        t.clear();
        t.resize(sz+1);
    }
    void clear(long long sz)
    {
        n=sz;
        t.clear();
        t.resize(sz+1);
    }
    void update(long long i, long long val)
    {
        while(i<=n)
        {
            t[i]+=val;
            i+=i&-i;
        }
    }
    long long query(long long i)
    {
        long long ans=0;
        while(i>0)
        {
            ans+=t[i];
            i-=i&-i;
        }
        return ans;
    }
};



int main()
{
    boost;
    int n;
    cin>>n;
pts.pb(-INF-1);
pts.pb(-INF-2);
pts.pb(-INF);
pts.pb(INF);
pts.pb(INF+1);
pts.pb(INF+2);
    FOR(i,0,n-1)
    {
        int x1,x2,y1,y2;

        cin>>x1>>y1>>x2>>y2;
        pts.pb(x1);pts.pb(x2);pts.pb(y1);pts.pb(y2);
        pts.pb(x1+1);pts.pb(x2+1);pts.pb(y1+1);pts.pb(y2+1);
        pts.pb(x1+2);pts.pb(x2+2);pts.pb(y1+2);pts.pb(y2+2);
        pts.pb(x1-1);pts.pb(x2-1);pts.pb(y1-1);pts.pb(y2-1);
        pts.pb(x1-2);pts.pb(x2-2);pts.pb(y1-2);pts.pb(y2-2);

        if(y1==y2)
        {
            ss.pb({y1,{min(x1,x2),max(x1,x2)}});
           // seg.pb({{x1,0},{y1,1}});
            //seg.pb({{x2,2},{y1,-1}});
            continue;
        }

        seg.pb({{x1,1},{min(y1,y2),max(y1,y2)}});
    }


    ufy(ss);
    ufy(pts);


    ll ans=0;

    FOR(i,0,sz(ss)-1)
    {
        if(i)
        if(ss[i-1].F==ss[i].F)
        {
            if(ss[i].S.S<=ss[i-1].S.S){ss[i]=ss[i-1];continue;}
                if(ss[i].S.F<=ss[i-1].S.S)
                ss[i].S.F=ss[i-1].S.S+1;
        }
        assert(ss[i].S.F<=ss[i].S.S);
        {
            ans+=ss[i].S.S-ss[i].S.F+1;
            seg.pb({{ss[i].S.F,0},{ss[i].F,1}});
            seg.pb({{ss[i].S.S,2},{ss[i].F,-1}});
        }

    }

    ufy(seg);
    //tr(seg,it)
    //cout<<it->F.F<<" "<<it->F.S<<" "<<it->S.F<<" "<<it->S.S<<"\n";

    BIT1 bt(pts.size()+10);

    FOR(i,0,sz(seg)-1)
    {

        if(seg[i].F.S==1)
        {


            if(i and seg[i-1].F.S==1 and seg[i-1].F.F==seg[i].F.F)
            {

                if(seg[i].S.S<=seg[i-1].S.S){seg[i]=seg[i-1];continue;}
                if(seg[i].S.F<=seg[i-1].S.S)
                seg[i].S.F=seg[i-1].S.S+1;
            }


                assert(seg[i].S.F<=seg[i].S.S);
            {
                ans+=seg[i].S.S-seg[i].S.F+1;
assert(pos(seg[i].S.F)-1==pos(seg[i].S.F-1));
                ans-=bt.query(pos(seg[i].S.S))-bt.query(pos(seg[i].S.F)-1);
            }

        }
        else
        {
            bt.update(pos(seg[i].S.F),seg[i].S.S);
        }
    }

cout<<ans;

    return 0;
}