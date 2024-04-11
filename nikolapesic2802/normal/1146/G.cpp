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

const int N=50*52;
struct edge{
    int next,capacity,rev;
};
int source=0,sink=N-1;
vector<vector<edge> > graf(N);
void addEdge(int i,int j,int c)
{
    edge a={j,c,(int)graf[j].size()},b={i,0,(int)graf[i].size()};
    graf[i].pb(a);
    graf[j].pb(b);
}
vector<int> level(N),st(N);
bool bfs()
{
    fill(all(st),0);
    fill(all(level),0);
    level[source]=1;
    queue<int> q;
    q.push(source);
    while(q.size())
    {
        int tr=q.front();
        q.pop();
        for(auto p:graf[tr])
            if(!level[p.next]&&p.capacity)
            {
                level[p.next]=level[tr]+1;
                q.push(p.next);
            }
    }
    return level[sink]!=0;
}
int dfs(int tr,int cap)
{
    if(tr==sink)
        return cap;
    for(;st[tr]<graf[tr].size();st[tr]++)
    {
        edge p=graf[tr][st[tr]];
        if(level[tr]+1!=level[p.next]||p.capacity==0)
            continue;
        if(int flow=dfs(p.next,min(cap,p.capacity)))
        {
            graf[tr][st[tr]].capacity-=flow;
            graf[p.next][p.rev].capacity+=flow;
            return flow;
        }
    }
    return 0;
}
int dinic()
{
    int flow=0;
    while(bfs())
        while(int d=dfs(source,INT_MAX))
            flow+=d;
    return flow;
}
int main()
{
    int n,h,m;
    scanf("%i %i %i",&n,&h,&m);
    for(int i=1;i<=n;i++)
    {
        int last=0;
        for(int j=0;j<h;j++)
        {
            addEdge(last,j*n+i,h*h-j*j);
            last=j*n+i;
        }
    }
    while(m--)
    {
        int l,r,x,c;
        scanf("%i %i %i %i",&l,&r,&x,&c);
        if(x==h)
            continue;
        for(int i=l;i<=r;i++)
        //{
            addEdge(x*n+i,h*n+1+m,INT_MAX);
        /*}
        for(int i=l;i<=r;i++)
            for(int j=x+1;j<=h;j++)
                addEdge((j-1)*n+i,h*n+1+m,INT_MAX);*/
        addEdge(h*n+1+m,sink,c);
    }
    int sol=h*h*n-dinic();
    printf("%i\n",sol);
    return 0;
}