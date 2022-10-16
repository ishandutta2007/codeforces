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
map<int,pair<int,pair<int,int> > > mapa;
vector<int> qu,pos;
vector<ll> sol;
pair<vector<int>,pair<int,int> > novo;
pair<int,int> start={-1,-1};
int N;
ll calc(pair<int,int> f,int po)
{
    return (ll)f.f*po+f.s;
}
struct liChao{
    vector<pair<int,int> > f;
    vector<pair<vector<int>,pair<int,int> > > moves;
    void init()
    {
        f.resize(4*N,start);
    }
    void add(pair<int,int> ne,int l=0,int r=N,int i=1)
    {
        if(i==1)
            moves.pb(novo);
        if(f[i]==start)
        {
            moves.back().s=start;
            moves.back().f.pb(i);
            swap(f[i],ne);
            return;
        }
        int m=(l+r)>>1;
        bool lft=calc(ne,pos[l])>calc(f[i],pos[l]);
        bool mid=calc(ne,pos[m])>calc(f[i],pos[m]);
        if(mid)
        {
            moves.back().f.pb(i);
            swap(ne,f[i]);
        }
        if(r-l==1)
        {
            moves.back().s=ne;
            return;
        }
        if(lft!=mid)
            add(ne,l,m,2*i);
        else
            add(ne,m,r,2*i+1);
    }
    ll get(int po,int l=0,int r=N,int i=1)
    {
        if(f[i]==start)
            return LLONG_MIN;
        if(r-l==1)
            return calc(f[i],po);
        int m=(l+r)>>1;
        if(pos[m]>po)
            return max(calc(f[i],po),get(po,l,m,2*i));
        return max(calc(f[i],po),get(po,m,r,2*i+1));
    }
    void undo()
    {
        pair<int,int> tr=moves.back().s;
        while(moves.back().f.size())
        {
            int i=moves.back().f.back();
            moves.back().f.pop_back();
            swap(tr,f[i]);
        }
        moves.pop_back();
    }
}lt;
struct segTree{
    vector<vector<pair<int,int> > > a;
    void init()
    {
        a.resize(4*N);
    }
    void add(int qs,int qe,pair<int,int> b,int l=0,int r=N-1,int i=1)
    {
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {
            a[i].pb(b);
            return;
        }
        int m=(l+r)>>1;
        add(qs,qe,b,l,m,2*i);
        add(qs,qe,b,m+1,r,2*i+1);
    }
    void solve(int l=0,int r=N-1,int i=1)
    {
        for(auto p:a[i])
            lt.add(p);
        if(l==r)
        {
            sol[l]=lt.get(qu[l]);
        }
        else
        {
            int m=(l+r)>>1;
            solve(l,m,2*i);
            solve(m+1,r,2*i+1);
        }
        for(auto p:a[i])
            lt.undo();
    }
}st;
int main()
{
	int n;
	scanf("%i",&n);
	int cnt=0;
	vector<pair<pair<int,int>,pair<int,int> > > adds;
	pair<int,pair<int,int> > null={-1,{-1,-1}};
	bool debug=false;
	for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%i",&t);
        if(t==1)
        {
            int a,b;
            scanf("%i %i",&a,&b);
            if(i==1&&n==200000&&t==1&&a==-305823393&&b==-957089218)
                debug=true;
            mapa[i]={cnt,{a,b}};
        }
        if(t==2)
        {
            int q;
            scanf("%i",&q);
            pair<int,pair<int,int> > p=mapa[q];
            if(p.f<cnt)
            {
                adds.pb({{p.f,cnt-1},{p.s.f,p.s.s}});
            }
            mapa[q]=null;
        }
        if(t==3)
        {
            int x;
            scanf("%i",&x);
            qu.pb(x);
            pos.pb(x);
            cnt++;
        }
    }
    for(auto d:mapa)
    {
        if(d.s!=null)
        {
            pair<int,pair<int,int> > p = d.s;
            if(p.f<cnt)
            {
                adds.pb({{p.f,cnt-1},{p.s.f,p.s.s}});
            }
        }
    }
    if(cnt==0)
        return 0;
    sort(all(pos));
    N=cnt;
    st.init();
    for(auto p:adds)
        st.add(p.f.f,p.f.s,p.s);
    sol.resize(N);
    lt.init();
    st.solve();
    for(int i=0;i<N;i++)
        if(sol[i]==LLONG_MIN)printf("EMPTY SET\n");else printf("%lld\n",sol[i]);
    return 0;
}