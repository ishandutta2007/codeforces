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

struct dsu{
    gp_hash_table<int,int> vertex;
    vector<int> par;
    int find(int tr)
    {
        if(tr==par[tr])
            return tr;
        return par[tr]=find(par[tr]);
    }
    void merge(int a,int b)
    {
        if(vertex.find(a)==vertex.end())
            vertex[a]=par.size(),par.pb(par.size());
        if(vertex.find(b)==vertex.end())
            vertex[b]=par.size(),par.pb(par.size());
        a=find(vertex[a]),b=find(vertex[b]);
        if(a!=b)
            par[a]=b;
    }
};
int main()
{
    int n,m;
	scanf("%i %i",&n,&m);
	vector<vector<int> > colors(n);
	vector<dsu> d(m+1);
	for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%i %i %i",&a,&b,&c);
        a--;b--;
        d[c].merge(a,b);
        colors[a].pb(c);
        colors[b].pb(c);
    }
    for(int i=0;i<n;i++)
        sort(all(colors[i])),colors[i].erase(unique(all(colors[i])),colors[i].end());
    int q;
    scanf("%i",&q);
    vector<int> ans(q);
    vector<pair<pair<int,int>,int> > qu(q);
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;b--;
        if(colors[a].size()>colors[b].size())
            swap(a,b);
        if(colors[a].size()==colors[b].size())
            if(a>b)
                swap(a,b);
        qu[i].f.f=a;
        qu[i].f.s=b;
        qu[i].s=i;
    }
    sort(all(qu));
    for(int i=0;i<q;i++)
    {
        if(i&&qu[i].f==qu[i-1].f){
            ans[qu[i].s]=ans[qu[i-1].s];
            continue;
        }
        int cnt=0;
        for(auto p:colors[qu[i].f.f])
        {
            if(d[p].vertex.find(qu[i].f.s)==d[p].vertex.end())
                continue;
            int aa=d[p].find(d[p].vertex[qu[i].f.f]),bb=d[p].find(d[p].vertex[qu[i].f.s]);
            if(aa==bb)
                cnt++;
        }
        ans[qu[i].s]=cnt;
    }
    for(int i=0;i<q;i++)
        printf("%i ",ans[i]);
    return 0;
}