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

const int N=203,source=201,sink=202;
struct edge{
    int nxt,cap,rev;
};
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
    fill(all(level),0);
    fill(all(st),0);
    level[source]=1;
    queue<int> q;
    q.push(source);
    while(q.size())
    {
        int tr=q.front();
        q.pop();
        for(auto p:graf[tr])
        {
            if(p.cap&&!level[p.nxt])
            {
                level[p.nxt]=level[tr]+1;
                q.push(p.nxt);
            }
        }
    }
    return level[sink]!=0;
}
int dfs(int tr,int c)
{
    if(tr==sink)
        return c;
    for(;st[tr]<(int)graf[tr].size();st[tr]++)
    {
        auto p=graf[tr][st[tr]];
        if(level[p.nxt]==level[tr]+1&&p.cap)
            if(int d=dfs(p.nxt,min(c,p.cap)))
            {
                graf[tr][st[tr]].cap-=d;
                graf[p.nxt][p.rev].cap+=d;
                return d;
            }
    }
    return 0;
}
int dinic()
{
    int f=0;
    while(bfs())
        while(int d=dfs(source,INT_MAX))
            f+=d;
    return f;
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	int imam=0;
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        imam+=a;
        addEdge(source,i,a);
        addEdge(i,i+n,INT_MAX);
    }
    int total=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        addEdge(n+i,sink,a);
        total+=a;
    }
    if(total!=imam)
    {
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        addEdge(a,n+b,INT_MAX);
        addEdge(b,n+a,INT_MAX);
    }
    int f=dinic();
    if(f!=total)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    vector<vector<int> > use(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(auto p:graf[i])
            if(p.nxt!=source&&p.nxt!=sink)
                use[i][p.nxt-n]+=INT_MAX-p.cap;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%i ",use[i][j]);
        printf("\n");
    }
    return 0;
}