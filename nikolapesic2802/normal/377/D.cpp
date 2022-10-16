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

const int N=3e5+5;
vector <int> lazy(4*N);
vector<pair<int,int> > maxx(4*N);
void build(int l=0,int r=N-1,int i=1)
{
    if(l==r)
    {
        maxx[i].s=l;
        return;
    }
    int m=(l+r)>>1;
    build(l,m,2*i);
    build(m+1,r,2*i+1);
    maxx[i]=max(maxx[2*i],maxx[2*i+1]);
}
void add(int qs,int qe,int v,int l=0,int r=N-1,int i=1)
{
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r)
    {
        maxx[i].f+=v;
        lazy[i]+=v;
        return;
    }
    maxx[2*i].f+=lazy[i];
    maxx[2*i+1].f+=lazy[i];
    lazy[2*i]+=lazy[i];
    lazy[2*i+1]+=lazy[i];
    lazy[i]=0;
    int m=(l+r)>>1;
    add(qs,qe,v,l,m,2*i);
    add(qs,qe,v,m+1,r,2*i+1);
    maxx[i]=max(maxx[2*i],maxx[2*i+1]);
}
vector<vector<pair<pair<int,int>,pair<int,int> > > > events(N);
int main()
{
    build();
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
    {
        int l,v,r;
        scanf("%i %i %i",&l,&v,&r);
        events[r].pb({{l,v},{1,i}});
        events[v-1].pb({{l,v},{-1,i}});
    }
    pair<int,int> sol={0,0};
    for(int i=N-1;i>=0;i--){
        for(auto p:events[i])
            add(p.f.f,p.f.s,p.s.f);
        sol=max(sol,maxx[1]);
    }
    printf("%i\n",sol.f);
    set<int> vals;
    for(int i=N-1;i>=0;i--)
    {
        for(auto p:events[i])
        {
            if(p.f.f<=sol.s&&p.f.s>=sol.s)
            {
                if(p.s.f==1)
                    vals.insert(p.s.s);
                else
                    vals.erase(p.s.s);
            }
        }
        if(vals.size()==sol.f)
        {
            for(auto p:vals)
                printf("%i ",p+1);
            return 0;
        }
    }
    return 0;
}