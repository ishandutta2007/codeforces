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

const int N=1e6+5;
vector<pair<ll,int> > ma(4*N);
vector<ll> lazy(4*N);
vector<int> vals;
int n;
void prop(int i)
{
    lazy[2*i]+=lazy[i];
    lazy[2*i+1]+=lazy[i];
    ma[2*i].f+=lazy[i];
    ma[2*i+1].f+=lazy[i];
    lazy[i]=0;
}
void build(int l=0,int r=N-1,int i=1)
{
    if(l==r)
    {
        ma[i]={vals[l],l};
        return;
    }
    int m=(l+r)>>1;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    ma[i]=max(ma[2*i],ma[2*i+1]);
}
void add(int qs,int qe,int x,int l=0,int r=N-1,int i=1)
{
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r)
    {
        ma[i].f+=x;
        lazy[i]+=x;
        return;
    }
    prop(i);
    int m=(l+r)>>1;
    add(qs,qe,x,l,m,2*i);
    add(qs,qe,x,m+1,r,2*i+1);
    ma[i]=max(ma[2*i],ma[2*i+1]);
}
pair<ll,int> get(int qs,int qe,int l=0,int r=N-1,int i=1)
{
    if(qs>r||qe<l)
        return {LLONG_MIN/2,-1};
    if(qs<=l&&qe>=r)
        return ma[i];
    int m=(l+r)>>1;
    prop(i);
    return max(get(qs,qe,l,m,2*i),get(qs,qe,m+1,r,2*i+1));
}
vector<pair<int,pair<int,int> > > points;
map<int,int> mapa;
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
        int x,y,c;
        scanf("%i %i %i",&x,&y,&c);
        vals.pb(x);
        vals.pb(y);
        points.pb({max(x,y),{min(x,y),c}});
    }
    sort(all(points));
    sort(all(vals));
    vals.erase(unique(all(vals)),vals.end());
    int m=vals.size(),it=0;
    for(int i=0;i<m;i++)
        mapa[vals[i]]=i;
    for(auto &p:points)
        p.f=mapa[p.f],p.s.f=mapa[p.s.f];
    points.pb({m,{-1,-1}});
    while(vals.size()<N)
        vals.pb(2e9);
    build();
    pair<pair<ll,int>,int> sol={{0,m},m};
    for(int i=0;i<m;i++)
    {
        while(points[it].f==i)
            add(0,points[it].s.f,points[it].s.s),it++;
        auto tr=get(0,i);
        tr.f-=vals[i];
        sol=max(sol,{tr,i});
    }
    printf("%lld\n%i %i %i %i\n",sol.f.f,vals[sol.f.s],vals[sol.f.s],vals[sol.s],vals[sol.s]);
    return 0;
}