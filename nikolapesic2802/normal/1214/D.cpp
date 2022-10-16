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

const int N=2e6+5;
int source,sink;
struct edge{
    int nxt,cap,rev;
};
vector<vector<edge> > graf(N);
void addEdge(int a,int b,int c)
{
    edge i={b,c,graf[b].size()},j={a,0,graf[a].size()};
    graf[a].pb(i);
    graf[b].pb(j);
}
vector<int> dist(N),st(N);
bool bfs()
{
    fill(all(dist),-1);
    fill(all(st),0);
    queue<int> q;
    q.push(source);
    dist[source]=0;
    while(q.size())
    {
        int tr=q.front();
        q.pop();
        for(auto p:graf[tr])
        {
            if(dist[p.nxt]!=-1||p.cap==0)
                continue;
            dist[p.nxt]=dist[tr]+1;
            q.push(p.nxt);
        }
    }
    return dist[sink]!=-1;
}
int dfs(int tr=source,int cap=INT_MAX)
{
    if(tr==sink)
        return cap;
    for(;st[tr]<graf[tr].size();st[tr]++)
    {
        auto p=graf[tr][st[tr]];
        if(p.cap==0||dist[p.nxt]!=dist[tr]+1)
            continue;
        if(int d=dfs(p.nxt,min(cap,p.cap)))
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
        while(int d=dfs())
            f+=d;
    return f;
}
vector<int> dx={1,0},dy={0,1};
int n,m;
vector<string> mat;
bool inside(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m&&mat[x][y]!='#';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin >> n >> m;
	source=1;sink=2*((n-1)*m+m-1);
	mat.resize(n);
	for(int i=0;i<n;i++)
        cin >> mat[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            addEdge(2*(i*m+j),2*(i*m+j)+1,1);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<2;k++)
            {
                int x=i+dx[k],y=j+dy[k];
                if(inside(x,y))
                    addEdge(2*(i*m+j)+1,2*(x*m+y),1);
            }
    cout << dinic() << endl;
    return 0;
}