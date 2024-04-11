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
vector<ll> solution(N);
vector<vector<pair<int,int> > > po;
void add(int qs,int qe,int x,int y,int l=0,int r=N-1,int i=1)
{
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r)
    {
        po[i].pb({x,y});
        return;
    }
    int m=(l+r)>>1;
    add(qs,qe,x,y,l,m,2*i);
    add(qs,qe,x,y,m+1,r,2*i+1);
}
struct node{
    int par,siz,cnt,rank;
};
vector<node> dsu(N);
void init()
{
    po.resize(4*N);
    for(int i=0;i<N;i++)
        dsu[i].par=i,dsu[i].siz=1,dsu[i].cnt=0,dsu[i].rank=1;
}
struct operacija{
    int type,koji,pre;
    operacija(int t,int k,int p)
    {
        type=t;
        koji=k;
        pre=p;
    }
    void undo()
    {
        if(type==1)
            dsu[koji].par=pre;
        if(type==2)
            dsu[koji].siz=pre;
        if(type==3)
            dsu[koji].cnt=pre;
        if(type==4)
            dsu[koji].rank=pre;
        //printf("Undo %i %i %i\n",type,koji,pre);
    }
};
vector<vector<operacija> > undo;
vector<operacija> blank;
int find(int x)
{
    if(dsu[x].par==x)
        return x;
    undo.back().pb(operacija(1,x,dsu[x].par));
    return dsu[x].par=find(dsu[x].par);
}
void merge(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
        return;
    if(dsu[a].rank==dsu[b].rank)
    {
        undo.back().pb(operacija(1,a,dsu[a].par));
        dsu[a].par=b;
        undo.back().pb(operacija(2,b,dsu[b].siz));
        dsu[b].siz+=dsu[a].siz;
        undo.back().pb(operacija(3,b,dsu[b].cnt));
        dsu[b].cnt+=dsu[a].cnt;
        undo.back().pb(operacija(4,b,dsu[b].rank));
        dsu[b].rank++;
        return;
    }
    if(dsu[a].rank<dsu[b].rank)
    {
        undo.back().pb(operacija(1,a,dsu[a].par));
        dsu[a].par=b;
        undo.back().pb(operacija(2,b,dsu[b].siz));
        dsu[b].siz+=dsu[a].siz;
        undo.back().pb(operacija(3,b,dsu[b].cnt));
        dsu[b].cnt+=dsu[a].cnt;
    }
    else
    {
        undo.back().pb(operacija(1,b,dsu[b].par));
        dsu[b].par=a;
        undo.back().pb(operacija(2,a,dsu[a].siz));
        dsu[a].siz+=dsu[b].siz;
        undo.back().pb(operacija(3,a,dsu[a].cnt));
        dsu[a].cnt+=dsu[b].cnt;
    }

}
void undoone()
{
    for(int i=undo.back().size()-1;i>=0;i--)
        undo.back()[i].undo();
    undo.pop_back();
}
vector<vector<int> > points(N);
vector<int> x(N);
ll trsol;
void solve(int l=0,int r=N-1,int i=1)
{
    undo.pb(blank);
    ll startsol=trsol;
    for(auto p:po[i])
    {
        points[p.f].pb(p.s);
        int b=find(points[p.f].back());
        if(x[p.f]==0)
        {
            undo.back().pb(operacija(3,b,dsu[b].cnt));
            dsu[b].cnt++;
            trsol+=dsu[b].siz;
        }
        if(points[p.f].size()>1)
        {
            int a=find(points[p.f].front());
            if(a!=b)
            {
                trsol+=(ll)dsu[a].siz*dsu[b].cnt+(ll)dsu[a].cnt*dsu[b].siz;
            }
            merge(a,b);
        }
        x[p.f]++;
    }
    if(r-l==0)
    {
        solution[l]=trsol;
    }
    else
    {
        int m=(l+r)>>1;
        solve(l,m,2*i);
        solve(m+1,r,2*i+1);
    }
    for(auto p:po[i])
    {
        points[p.f].pop_back();
        x[p.f]--;
    }
    trsol=startsol;
    undoone();
}
map<int,int> imam[N];
int main()
{
    init();
	int q;
	scanf("%i",&q);
	for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%i %i",&x,&y);
        if(imam[x][y]!=0)
        {
            add(imam[x][y]-1,i-1,x,y);
            imam[x][y]=0;
        }
        else
        {
            imam[x][y]=i+1;
        }
    }
    for(int i=0;i<N;i++)
        for(auto p:imam[i])
        {
            if(p.s!=0)
            {
                add(p.s-1,q-1,i,p.f);
            }
        }
    solve();
    for(int i=0;i<q;i++)
        printf("%lld ",solution[i]);
    return 0;
}