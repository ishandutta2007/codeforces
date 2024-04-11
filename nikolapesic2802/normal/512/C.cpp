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

bool isPrime(int i)
{
    for(int j=2;j*j<=i;j++)
        if(i%j==0)
            return false;
    return true;
}
struct edge{
    int nxt,rev,cap;
};
const int N=205,source=200,sink=201;
vector<vector<edge> > graf(N);
void addEdge(int i,int j,int c)
{
    edge a={j,graf[j].size(),c},b={i,graf[i].size(),0};
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
            if(level[p.nxt]||p.cap==0)
                continue;
            level[p.nxt]=level[tr]+1;
            q.push(p.nxt);
        }
    }
    return level[sink];
}
int dfs(int tr,int cap)
{
    if(tr==sink)
        return cap;
    for(;st[tr]<(int)graf[tr].size();st[tr]++)
    {
        edge &p=graf[tr][st[tr]];
        if(level[p.nxt]!=level[tr]+1||p.cap==0)
            continue;
        if(int f=dfs(p.nxt,min(cap,p.cap)))
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
        while(int d=dfs(source,INT_MAX/2))
            f+=d;
    return f;
}
int main()
{
	int n;
	scanf("%i",&n);
	vector<int> a(n);
	for(int i=0;i<n;i++)
    {
        scanf("%i",&a[i]);
        if(a[i]%2)
            addEdge(source,i,2);
        else
            addEdge(i,sink,2);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i]%2&&isPrime(a[i]+a[j]))
                addEdge(i,j,1);
    int f=dinic();
    if(f!=n){
        printf("Impossible\n");
        return 0;
    }
    vector<int> visited(n);
    int trVal=1;
    vector<vector<int> > components(n+1);
    for(int i=0;i<n;i++)
    {
        if(visited[i])
            continue;
        visited[i]=trVal;
        components[trVal].pb(i);
        stack<int> q;
        q.push(i);
        while(q.size())
        {
            int tr=q.top();
            q.pop();
            for(auto p:graf[tr])
            {
                if(p.nxt>=n||visited[p.nxt])
                    continue;
                if(a[tr]%2)
                {
                    if(p.cap!=0)
                        continue;
                }
                else
                    if(p.cap!=1)
                        continue;
                q.push(p.nxt);
                visited[p.nxt]=trVal;
                components[trVal].pb(p.nxt);
                break;
            }
        }
        trVal++;
    }
    printf("%i\n",trVal-1);
    for(int i=1;i<trVal;i++)
    {
        printf("%i ",components[i].size());
        for(auto p:components[i])
            printf("%i ",p+1);
        printf("\n");
    }
    return 0;
}