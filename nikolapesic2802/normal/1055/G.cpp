#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

struct pt{
    ll x,y;
    pt operator-(pt a){return {x-a.x,y-a.y};}
    pt operator+(pt a){return {x+a.x,y+a.y};}
    pt operator*(ll a){return {x*a,y*a};}
};
bool operator<(pt a,pt b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool operator==(pt a,pt b){return a.x==b.x&&a.y==b.y;}
ll cross(pt a,pt b){return a.x*b.y-a.y*b.x;}
ll dot(pt a,pt b){return a.x*b.x+a.y*b.y;}
ll sq(pt a){return a.x*a.x+a.y*a.y;}
ostream& operator<<(ostream& out,pt a){out << "[" << a.x << "," << a.y << "]"; return out;}
struct line{
    pt v;
    ll c;
    line(pt a,pt b){v=b-a;c=cross(v,a);}
};
ll side(line a,pt v){return a.c-cross(a.v,v);}
void rotate(vector<pt> &points)
{
    pt m=points[0];
    for(auto p:points)
        if(p<m)
            m=p;
    vector<pt> novo;
    for(int i=0,n=points.size();i<n;i++)
        if(points[i]==m)
            for(int j=0;j<n;j++)
                novo.pb(points[(i+j)%n]);
    points=novo;
}
vector<pt> operator*(vector<pt> a,vector<pt> b)
{
    rotate(a);
    rotate(b);
    vector<pt> sol;
    int tra=0,trb=0,asiz=a.size(),bsiz=b.size();
    while(tra<asiz||trb<bsiz)
    {
        sol.pb(a[tra%asiz]+b[trb%bsiz]);
        ll c=cross(a[(tra+1)%asiz]-a[tra%asiz],b[(trb+1)%bsiz]-b[trb%bsiz]);
        if(c==0)
            tra++,trb++;
        if(c>0)
            tra++;
        if(c<0)
            trb++;
    }
    return sol;
}
bool checkInside(vector<pt> a,pt b)
{
    for(int i=0,n=a.size();i<n;i++)
        if(cross(a[(i+1)%n]-a[i],b-a[i])<=0)
            return false;
    return true;
}
bool check(vector<pt> a,pt b,ll r)
{
    if(checkInside(a,b))
        return 1;
    for(auto p:a)
        if(sq(p-b)<r*r)
            return 1;
    for(int i=0,n=a.size();i<n;i++)
        if(dot(a[(i+1)%n]-a[i],b-a[i])>0&&dot(a[i]-a[(i+1)%n],b-a[(i+1)%n])>0)
        {
            line tr(a[(i+1)%n],a[i]);
            if(side(tr,b)*side(tr,b)<sq(tr.v)*r*r)
                return 1;
        }
    return 0;
}
int source=499,sink=500,oo=1000;
struct edge{
    int nxt,cap,rev;
};
vector<vector<edge> > graf(sink+1);
void addEdge(int a,int b,int c)
{
    edge i={b,c,graf[b].size()},j={a,0,graf[a].size()};
    graf[a].pb(i);
    graf[b].pb(j);
}
vector<int> level(501),st(501);
bool bfs()
{
    fill(all(level),-1);
    fill(all(st),0);
    level[source]=0;
    queue<int> q;
    q.push(source);
    while(q.size())
    {
        int tr=q.front();
        q.pop();
        for(auto p:graf[tr])
        {
            if(level[p.nxt]!=-1||p.cap==0)
                continue;
            level[p.nxt]=level[tr]+1;
            q.push(p.nxt);
        }
    }
    return level[sink]!=-1;
}
int dfs(int tr,int flow)
{
    if(tr==sink)
        return flow;
    for(auto &p:graf[tr])
    {
        if(level[p.nxt]!=level[tr]+1||p.cap==0)
            continue;
        if(int f=dfs(p.nxt,min(flow,p.cap)))
        {
            p.cap-=f;
            graf[p.nxt][p.rev].cap+=f;
            return f;
        }
    }
    return 0;
}
int dinic()
{
    int f=0;
    while(bfs())
        while(int d=dfs(source,oo))
            f+=d;
    return f;
}
int main()
{
    int n,w;
    scanf("%i %i",&n,&w);
    vector<pt> a(n),b,sum;
    for(int i=0;i<n;i++)
        scanf("%lld %lld",&a[i].x,&a[i].y);
    ll mn=INT_MAX,mx=-1;
    for(auto p:a)
        mn=min(mn,p.x),mx=max(mx,p.x);
    ll len=mx-mn;
    for(auto p:a)
        b.pb(p*-1);
    sum=a*b;
    int m;
    scanf("%i",&m);
    vector<pair<pt,ll> > jelly(m);
    for(int i=0;i<m;i++)
        scanf("%lld %lld %lld",&jelly[i].f.x,&jelly[i].f.y,&jelly[i].s),addEdge(2*i,2*i+1,1);
    for(int i=0;i<m;i++)
    {
        if(len>jelly[i].f.x-jelly[i].s)
            addEdge(source,2*i,oo);
        if(len>w-jelly[i].f.x-jelly[i].s)
            addEdge(2*i+1,sink,oo);
    }
    for(int i=0;i<m;i++)
        for(int j=i+1;j<m;j++)
            if(check(sum,jelly[i].f-jelly[j].f,jelly[i].s+jelly[j].s))
                addEdge(2*i+1,2*j,oo),addEdge(2*j+1,2*i,oo);
    printf("%i\n",dinic());
    return 0;
}