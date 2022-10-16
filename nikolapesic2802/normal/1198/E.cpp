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

const int N=51,M=202,source=400,sink=401,oo=INT_MAX/2;
vector<int> x1(N),x2(N),y1(N),y2(N),x,y;
int n;
struct edge{
    int nxt,cap,rev;
};
vector<vector<edge> > graf(2*M);
void addEdge(int a,int b,int c)
{
    edge i={b,c,graf[b].size()},j={a,0,graf[a].size()};
    graf[a].pb(i);
    graf[b].pb(j);
}
map<int,int> mx,my;
vector<vector<int> > yes(M,vector<int>(M));
vector<int> level(2*M),st(2*M);
bool bfs()
{
    fill(all(level),-1);
    fill(all(st),0);
    queue<int> q;
    q.push(source);
    level[source]=0;
    while(q.size())
    {
        int tr=q.front();
        q.pop();
        for(auto p:graf[tr])
            if(p.cap!=0&&level[p.nxt]==-1)
                level[p.nxt]=level[tr]+1,q.push(p.nxt);
    }
    return level[sink]!=-1;
}
int dfs(int tr=source,int c=oo)
{
    if(tr==sink)
        return c;
    for(;st[tr]<(int)graf[tr].size();st[tr]++)
    {
        auto p=graf[tr][st[tr]];
        if(p.cap==0||level[p.nxt]!=level[tr]+1)
            continue;
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
    int a=0;
    while(bfs())
        while(int d=dfs())
            a+=d;
    return a;
}
int main()
{
    scanf("%i %i",&n,&n);
	for(int i=0;i<n;i++)
        scanf("%i %i %i %i",&x1[i],&y1[i],&x2[i],&y2[i]),x.pb(x1[i]),x.pb(x2[i]),y.pb(y1[i]),y.pb(y2[i]),x.pb(x2[i]+1),y.pb(y2[i]+1);
    sort(all(x));
    sort(all(y));
    x.erase(unique(all(x)),x.end());
    y.erase(unique(all(y)),y.end());
    for(int i=0;i<(int)x.size();i++)
        mx[x[i]]=i;
    for(int i=0;i<(int)y.size();i++)
        my[y[i]]=i;
    for(int i=0;i<n;i++)
        for(int j=mx[x1[i]];j<=mx[x2[i]];j++)
            for(int o=my[y1[i]];o<=my[y2[i]];o++)
                yes[j][o]=1;
    for(int i=0;i<(int)x.size()-1;i++)
        addEdge(source,i,x[i+1]-x[i]);
    for(int i=0;i<(int)y.size()-1;i++)
        addEdge(M+i,sink,y[i+1]-y[i]);
    for(int i=0;i<(int)x.size();i++)
        for(int j=0;j<(int)y.size();j++)
            if(yes[i][j])
                addEdge(i,M+j,oo);
    printf("%i\n",dinic());
    return 0;
}