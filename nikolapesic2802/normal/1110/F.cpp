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
const int N=5e5+5;
vector<vector<pair<int,int> > > graf(N);
vector<ll> sol(N);
vector<vector<pair<pair<int,int>,int> > > qu(N);
vector<int> in(N),out(N);
vector<ll> depth(N);
int timee=-1;
void dfs(int tr,int par)
{
    timee++;
    in[tr]=timee;
    for(auto p:graf[tr])
    {
        if(p.f==par)
            continue;
        depth[p.f]=depth[tr]+p.s;
        dfs(p.f,tr);
    }
    out[tr]=timee;
}
struct segTree{
    vector<ll> minn;
    vector<ll> lazy;
    void init()
    {
        minn.resize(4*N);
        lazy.resize(4*N);
    }
    void update(int i)
    {
        minn[i]=min(minn[2*i],minn[2*i+1]);
    }
    void prop(int i)
    {
        lazy[2*i]+=lazy[i];
        minn[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
        minn[2*i+1]+=lazy[i];
        lazy[i]=0;
    }
    void add(int qs,int qe,ll x,int l=0,int r=N-1,int i=1)
    {
        if(qs>qe)
            return;
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {
            lazy[i]+=x;
            minn[i]+=x;
            return;
        }
        int m=(l+r)>>1;
        prop(i);
        add(qs,qe,x,l,m,2*i);
        add(qs,qe,x,m+1,r,2*i+1);
        update(i);
    }
    ll get(int qs,int qe,int l=0,int r=N-1,int i=1)
    {
        if(qs>r||qe<l)
            return LLONG_MAX;
        if(qs<=l&&qe>=r)
            return minn[i];
        int m=(l+r)>>1;
        prop(i);
        return min(get(qs,qe,l,m,2*i),get(qs,qe,m+1,r,2*i+1));
    }
}st;
void solve(int tr,int par)
{
    for(auto p:qu[tr])
        sol[p.s]=st.get(p.f.f,p.f.s)+depth[tr];
    for(auto p:graf[tr])
    {
        if(p.f==par)
            continue;
        st.add(in[p.f],out[p.f],-2*p.s);
        solve(p.f,tr);
        st.add(in[p.f],out[p.f],2*p.s);
    }
}
int main()
{
    st.init();
	int n,q;
	scanf("%i %i",&n,&q);
	for(int i=1;i<n;i++)
    {
        int p,w;
        scanf("%i %i",&p,&w);
        p--;
        graf[p].pb({i,w});
        graf[i].pb({p,w});
    }
    for(int i=0;i<n;i++)
        sort(all(graf[i]));
    for(int i=0;i<q;i++)
    {
        int v,l,r;
        scanf("%i %i %i",&v,&l,&r);
        v--;l--;r--;
        qu[v].pb({{l,r},i});
    }
    dfs(0,-1);
    for(int i=0;i<n;i++)
    {
        if(graf[i].size()==1)
            st.add(i,i,depth[i]);
        else
            st.add(i,i,LLONG_MAX/10);
    }
    solve(0,-1);
    for(int i=0;i<q;i++)
        printf("%lld\n",sol[i]);
    return 0;
}