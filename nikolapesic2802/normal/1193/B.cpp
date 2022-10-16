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
const int N=1e5+5;
int n,k;
vector<vector<int> > graf(N);
vector<int> d(N,-1),w(N);
set<int> h;
vector<set<int> > dist;
struct node{
    int l,r;
    ll maxx,lazy,pos;
};
vector<node> drvo;
int newNode()
{
    node a;
    a.l=a.r=-1;
    a.maxx=a.lazy=a.pos=0;
    drvo.pb(a);
    return drvo.size()-1;
}
void prop(int i,int l,int m,int r)
{
    if(drvo[i].l==-1)
    {
        int a=newNode();
        drvo[i].l=a;
        a=newNode();
        drvo[i].r=a;
    }
    if(drvo[i].pos)
    {
        drvo[drvo[i].l].maxx=drvo[drvo[i].r].maxx=drvo[i].pos;
        drvo[drvo[i].l].lazy=drvo[drvo[i].r].lazy=0;
        drvo[drvo[i].l].pos=drvo[drvo[i].r].pos=drvo[i].pos;
        drvo[i].pos=0;
    }
    if(drvo[i].lazy)
    {
        drvo[drvo[i].l].maxx+=drvo[i].lazy;
        drvo[drvo[i].r].maxx+=drvo[i].lazy;
        drvo[drvo[i].l].lazy+=drvo[i].lazy;
        drvo[drvo[i].r].lazy+=drvo[i].lazy;
        drvo[i].lazy=0;
    }
}
void update(int i)
{
    drvo[i].maxx=max(drvo[drvo[i].l].maxx,drvo[drvo[i].r].maxx);
}
void add(int qs,int qe,ll x,int i,int l=0,int r=k-1)
{
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r)
    {
        drvo[i].maxx+=x;
        drvo[i].lazy+=x;
        return;
    }
    int m=(l+r)>>1;
    prop(i,l,m,r);
    add(qs,qe,x,drvo[i].l,l,m);
    add(qs,qe,x,drvo[i].r,m+1,r);
    update(i);
}
void sett(int qs,int qe,ll x,int i,int l=0,int r=k-1)
{
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r)
    {
        drvo[i].pos=drvo[i].maxx=x;
        drvo[i].lazy=0;
        return;
    }
    int m=(l+r)>>1;
    prop(i,l,m,r);
    sett(qs,qe,x,drvo[i].l,l,m);
    sett(qs,qe,x,drvo[i].r,m+1,r);
    update(i);
}
int first_larger(ll x,int i,int l=0,int r=k-1)
{
    if(drvo[i].maxx<x)
        return k;
    if(l==r)
        return l;
    int m=(l+r)>>1;
    prop(i,l,m,r);
    if(drvo[drvo[i].l].maxx>=x)
        return first_larger(x,drvo[i].l,l,m);
    return first_larger(x,drvo[i].r,m+1,r);
}
ll get(int pos,int i,int l=0,int r=k-1)
{
    if(l==r||drvo[i].l==-1)
        return drvo[i].maxx;
    int m=(l+r)>>1;
    prop(i,l,m,r);
    if(pos<=m)
        return get(pos,drvo[i].l,l,m);
    return get(pos,drvo[i].r,m+1,r);
}
pair<int,int> solve(int tr,int par)
{
    vector<pair<int,pair<int,int> > > ind;
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        auto s=solve(p,tr);
        ind.pb({dist[s.s].size(),s});
    }
    if(ind.size()==0)
    {
        dist.pb(h);
        int a=newNode();
        pair<int,int> s={a,dist.size()-1};
        if(d[tr]!=-1)
            add(d[tr],k-1,w[tr],s.f),dist[s.s].insert(d[tr]);
        return s;
    }
    sort(all(ind));
    auto s=ind.back().s;
    ind.pop_back();
    for(auto p:ind)
    {
        ll last=0;
        for(auto d:dist[p.s.s])
        {
            dist[s.s].insert(d);
            ll g=get(d,p.s.f);
            add(d,k-1,g-last,s.f);
            last=g;
        }
    }
    if(d[tr]!=-1)
    {
        ll val=get(d[tr],s.f)+w[tr];
        int i=first_larger(val,s.f);
        sett(d[tr],i-1,val,s.f);
        dist[s.s].insert(d[tr]);
    }
    return s;
}
int main()
{
    int m,a,b,c;
	scanf("%i %i %i",&n,&m,&k);
    for(int i=1;i<n;i++)
        scanf("%i",&a),graf[i].pb(a-1),graf[a-1].pb(i);
    for(int i=0;i<m;i++)
        scanf("%i %i %i",&a,&b,&c),d[a-1]=b-1,w[a-1]=c;
    int tr=solve(0,0).f;
    printf("%lld\n",get(k-1,tr));
    return 0;
}