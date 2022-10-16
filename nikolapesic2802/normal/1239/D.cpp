#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define f first
#define s second
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=1e6;
vector<vector<int> > graf(N);
vector<int> order;
vector<int> visited(N);
vector<int> inComponent(N);
vector<int> degree(N);
void dfs(int tr)
{
    visited[tr]=1;
    for(auto p:graf[tr])
        if(!visited[p])
            dfs(p);
    order.pb(tr);
}
vector<int> component;
vector<vector<int> > components;
void dfs2(int tr)
{
    visited[tr]=1;
    component.pb(tr);
    for(auto p:graf[tr])
        if(!visited[p])
            dfs2(p);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	scanf("%i",&t);
	while(t--)
    {
        int n,m;
        scanf("%i %i",&n,&m);
        vector<pair<int,int> > edges;
        for(int i=0;i<n;i++)
            graf[i].clear(),visited[i]=0;
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%i %i",&a,&b);
            a--;b--;
            if(a!=b)
                edges.pb({a,b}),graf[a].pb(b);
        }
        for(int i=0;i<n;i++)
            if(!visited[i])
                dfs(i);
        for(int i=0;i<n;i++)
            graf[i].clear(),visited[i]=0;
        for(auto p:edges)
            graf[p.s].pb(p.f);
        int cnt=0;
        components.clear();
        while(order.size())
        {
            if(visited[order.back()])
            {
                order.pop_back();
                continue;
            }
            component.clear();
            dfs2(order.back());
            order.pop_back();
            for(auto p:component)
                inComponent[p]=cnt;
            components.pb(component);
            cnt++;
        }
        if(component.size()==n)
        {
            printf("No\n");
            continue;
        }
        for(int i=0;i<cnt;i++)
            degree[i]=0;
        for(auto p:edges)
            if(inComponent[p.f]!=inComponent[p.s])
                degree[inComponent[p.f]]++;
        int koji;
        for(int i=0;i<cnt;i++)
            if(degree[i]==0)
                koji=i;
        printf("Yes\n%i %i\n",components[koji].size(),n-components[koji].size());
        for(auto p:components[koji])
            printf("%i ",p+1);
        printf("\n");
        vector<int> inC(n);
        for(auto p:components[koji])
            inC[p]=1;
        for(int i=0;i<n;i++)
            if(!inC[i])
                printf("%i ",i+1);
        printf("\n");
    }
    return 0;
}