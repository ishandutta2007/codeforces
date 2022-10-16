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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
const int N=1e5+5;
vector<int> visited(N);
vector<vector<pair<int,int> > > graf(N),start(N);
map<pair<int,int>,vector<int> > mapa[N];
bool dfs(int tr)
{
    visited[tr]=1;
    for(auto p:graf[tr])
    {
        int sl=p.f;
        if(visited[sl]==2)
            continue;
        if(visited[sl]==0)
        {
            if(dfs(sl))
                return true;
            continue;
        }
        return true;
    }
    visited[tr]=2;
    return false;
}
bool test(int v)
{
    //printf("Testiram %i\n",v);
    for(int i=0;i<N;i++)
    {
        graf[i].clear();
        for(auto p:start[i])
            if(p.s>v)
                graf[i].pb(p);
    }
    fill(all(visited),0);
    for(int i=0;i<N;i++)
    {
        if(visited[i]==0)
            if(dfs(i))
                return false;
    }
    return true;
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%i %i %i",&a,&b,&c);
        a--;b--;
        mapa[a][{b,c}].pb(i+1);
        start[a].pb({b,c});
    }
    int l=0,r=1e9;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(test(mid))
            r=mid;
        else
            l=mid+1;
    }
    vector<int> dist(n),in(n),li;
    vector<pair<int,pair<int,int> > > lis;
    for(int i=0;i<N;i++)
    {
        graf[i].clear();
        for(auto p:start[i])
            if(p.s>l)
                graf[i].pb(p),in[p.f]++;
            else
                lis.pb({i,p});
    }
    queue<int> q;
    for(int i=0;i<n;i++)
        if(in[i]==0)
            q.push(i);
    int cnt=0;
    while(q.size())
    {
        int tr=q.front();
        q.pop();
        dist[tr]=++cnt;
        for(auto p:graf[tr])
        {
            in[p.f]--;
            if(in[p.f]==0)
                q.push(p.f);
        }
    }
    sort(all(lis));
    lis.erase(unique(all(lis)),lis.end());
    for(auto p:lis)
    {
        if(dist[p.f]>dist[p.s.f])
            for(auto d:mapa[p.f][p.s])
                li.pb(d);
    }
    printf("%i %i\n",l,li.size());
    for(auto p:li)
        printf("%i ",p);
    printf("\n");
    return 0;
}