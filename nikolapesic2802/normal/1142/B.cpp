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
const int N=2e5+5;
vector<int> duzina(N);
vector<int> poz(N,-1);
int n;
struct segTree{
    vector<int> minn;
    void init()
    {
        minn.resize(4*N,INT_MAX);
    }
    void set(int pos,int val,int l=0,int r=N-1,int i=1)
    {
        if(l>pos||r<pos)
            return;
        if(pos==l&&pos==r)
        {
            minn[i]=val;
            return;
        }
        int m=(l+r)>>1;
        set(pos,val,l,m,2*i);
        set(pos,val,m+1,r,2*i+1);
        minn[i]=min(minn[2*i],minn[2*i+1]);
    }
    int get(int qs,int qe,int l=0,int r=N-1,int i=1)
    {
        if(qs>r||qe<l)
            return INT_MAX;
        if(qs<=l&&qe>=r)
        {
            return minn[i];
        }
        int m=(l+r)>>1;
        return min(get(qs,qe,l,m,2*i),get(qs,qe,m+1,r,2*i+1));
    }
}st;
vector<int> in;
vector<vector<int> > graf(N);
vector<int> visited(N);
void calc(int tr)
{
    visited[tr]=1;
    in.pb(tr);
    if(in.size()>=n)
    {
        poz[tr]=in[in.size()-n];
    }
    for(auto p:graf[tr])
    {
        if(visited[p])
            assert(0);
        calc(p);
    }
    in.pop_back();
}
int main()
{
    st.init();
	int m,q;
	scanf("%i %i %i",&n,&m,&q);
	if(n==1)
    {
        for(int i=0;i<q;i++)
            printf("1");
        return 0;
    }
	vector<int> p(n);
	for(int i=0;i<n;i++)
        scanf("%i",&p[i]);
    p.pb(p[0]);
    map<int,int> nxt;
    for(int i=0;i<n;i++)
        nxt[p[i]]=p[i+1];
    set<pair<int,int> > yes;
    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%i",&a);
        auto it=yes.lower_bound({a,0});
        while(it!=yes.end()&&(*it).f==a)
        {
            graf[i].pb((*it).s);
            yes.erase(it);
            it=yes.lower_bound({a,0});
        }
        yes.insert({nxt[a],i});
    }
    for(int i=m-1;i>=0;i--)
        if(!visited[i])
            calc(i);
    for(int i=0;i<m;i++)
    {
        if(poz[i]!=-1)
            st.set(i,poz[i]);
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%i %i",&l,&r);
        l--;r--;
        if(st.get(l,r)<=r)
            printf("1");
        else
            printf("0");
    }
    return 0;
}