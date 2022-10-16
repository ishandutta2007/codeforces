#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
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
const int N=1e5+5;
vector<vector<int> > graf(N),graf2(N),rev(N);
vector<int> order,component(N),visited(N),cycle(N);
int n,m,a,b,c,sol;
void dfs(int tr){
    visited[tr]=1;
    for(auto p:graf[tr])
        if(!visited[p])
            dfs(p);
    order.pb(tr);
}
void dfs1(int tr){
    component[tr]=c;
    for(auto p:graf2[tr])
        if(!component[p])
            dfs1(p);
}
int dfs2(int tr){
    int siz=1;
    visited[tr]=1;
    for(auto p:rev[tr])
        if(!visited[p])
            siz+=dfs2(p);
    return siz;
}
int main()
{
	scanf("%i %i",&n,&m);
	for(int i=0;i<m;i++)
        scanf("%i %i",&a,&b),a--,b--,graf[a].pb(b),graf2[a].pb(b),graf2[b].pb(a),rev[b].pb(a);
    for(int i=0;i<n;i++)
        if(!visited[i])
            dfs(i);
    for(int i=0;i<n;i++)
        if(!component[i])
            c++,dfs1(i);
    sol=n-c;
    fill(all(visited),0);
    reverse(all(order));
    for(auto p:order)
        if(!visited[p]&&dfs2(p)!=1&&cycle[component[p]]==0)
            cycle[component[p]]=1,sol++;
    printf("%i\n",sol);
    return 0;
}