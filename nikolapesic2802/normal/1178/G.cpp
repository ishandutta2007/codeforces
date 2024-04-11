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
#define ld long double

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

const int S=450,N=2e5+5;
struct line{
    ll k,n;
    ll get(ll pos){return k*pos+n;}
};
bool operator<(line a,line b)
{
    return a.k<b.k;
}
ld to(line a,line b){return (ld)(b.n-a.n)/(a.k-b.k);}
struct block{
    ll pos;
    vector<pair<line,int> > lines;
    deque<line> hull;
    void add(int l,int r,ll pp)
    {
        for(auto &p:lines)
            if(p.s>=l&&p.s<=r)
                p.f.n+=p.f.k*pp;
        build();
    }
    void inc(ll a)
    {
        pos+=a;
    }
    void build()
    {
        hull.clear();
        for(auto p:lines)
        {
            if(hull.size()&&hull.back().k==p.f.k&&hull.back().n>=p.f.n)
                continue;
            while(hull.size()&&hull.back().n<=p.f.n)
                hull.pop_back();
            while(hull.size()>1&&to(hull.back(),hull[hull.size()-2])>=to(p.f,hull.back()))
                hull.pop_back();
            hull.pb(p.f);
        }
    }
    ll get(int l,int r)
    {
        ll sol=LLONG_MIN;
        for(auto p:lines)
            if(p.s>=l&&p.s<=r)
                sol=max(sol,p.f.get(pos));
        return sol;
    }
    ll get()
    {
        while(hull.size()>1&&hull[1].get(pos)>=hull[0].get(pos))
            hull.pop_front();
        return hull[0].get(pos);
    }
};
vector<block> b(S);
void add(int l,int r,ll x)
{
    if(l/S==r/S)
        b[l/S].add(l,r,x);
    else
    {
        b[l/S].add(l,r,x);
        b[r/S].add(l,r,x);
        for(int i=l/S+1;i<r/S;i++)
            b[i].inc(x);
    }
}
ll get(int l,int r)
{
    if(l/S==r/S)
        return b[l/S].get(l,r);
    else
    {
        ll sol=LLONG_MIN;
        sol=max(sol,b[l/S].get(l,r));
        sol=max(sol,b[r/S].get(l,r));
        for(int i=l/S+1;i<r/S;i++)
            sol=max(sol,b[i].get());
        return sol;
    }
}
vector<vector<int> > graf(N);
vector<int> a(N),b1(N),in(N),out(N);
int t;
void dfs(int tr,int par,int aa,int bb)
{
    in[tr]=t++;
    aa+=a[tr];
    bb+=b1[tr];
    if(aa<0)
        b[in[tr]/S].lines.pb({{-abs(bb),(ll)abs(aa)*abs(bb)},in[tr]}),b[in[tr]/S].lines.pb({{abs(bb),-(ll)abs(aa)*abs(bb)},in[tr]});
    else
        b[in[tr]/S].lines.pb({{abs(bb),(ll)abs(aa)*abs(bb)},in[tr]});
    for(auto p:graf[tr])
        if(p!=par)
            dfs(p,tr,aa,bb);
    out[tr]=t-1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,q,c;
    scanf("%i %i",&n,&q);
    for(int i=1;i<n;i++)
        scanf("%i",&c),graf[i].pb(c-1),graf[c-1].pb(i);
    for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%i",&b1[i]);
    dfs(0,0,0,0);
    for(int i=0;i<S;i++)
        sort(all(b[i].lines)),b[i].build();
    for(int i=0;i<q;i++)
    {
        int t,a,b;
        scanf("%i",&t);
        if(t==1)
            scanf("%i %i",&a,&b),add(in[a-1],out[a-1],b);
        else
            scanf("%i",&a),printf("%lld\n",get(in[a-1],out[a-1]));
    }
}