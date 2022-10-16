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

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
int N=2e3+5;
struct Edge{
    int next;
    int capacity;
    int reverse;
};
vector<vector<Edge> > graf(N);
void addEdge(int i,int j,int c){
    Edge a{j,c,graf[j].size()};
    Edge b{i,0,graf[i].size()};
    graf[i].pb(a);
    graf[j].pb(b);
}
vector<int> st(N),levels(N);
bool BFS(int s,int t)
{
    fill(st.begin(),st.end(),0);
    fill(levels.begin(),levels.end(),-1);
    levels[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int tr=q.front();
        q.pop();
        for(Edge p:graf[tr])
        {
            if(p.capacity==0||levels[p.next]!=-1)
                continue;
            levels[p.next]=levels[tr]+1;
            q.push(p.next);
        }
    }
    return levels[t]!=-1;
}
int dfs(int tr,int limit,int t)
{
    if(tr==t)
        return limit;
    for(;st[tr]<graf[tr].size();st[tr]++)
    {
        Edge p=graf[tr][st[tr]];
        if(levels[tr]+1!=levels[p.next]||p.capacity==0)
            continue;
        int flow=dfs(p.next,min(limit,p.capacity),t);
        if(flow>0)
        {
            graf[tr][st[tr]].capacity-=flow;
            graf[graf[tr][st[tr]].next][graf[tr][st[tr]].reverse].capacity+=flow;
            return flow;
        }
    }
    return 0;
}
ll Dinics(int s,int t)
{
    ll total=0;
    while(BFS(s,t))
        while(int flow=dfs(s,INT_MAX,t))
            total+=(ll)flow;
    return total;
}
int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%i",&a);
        addEdge(0,i,a);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        scanf("%i %i %i",&a,&b,&w);
        addEdge(a,n+i,INT_MAX);
        addEdge(b,n+i,INT_MAX);
        addEdge(n+i,n+m+1,w);
        sum+=(ll)w;
    }
    sum-=Dinics(0,n+m+1);
    printf("%lld\n",sum);
    return 0;
}