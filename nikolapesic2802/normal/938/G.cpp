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
const int N=2e5+5;
vector<int> x(N),p(N),r(N);
void inittt()
{
    for(int i=0;i<N;i++)
        p[i]=i;
}
int find(int a){
    if(p[a]==a)
        return a;
    return find(p[a]);
}
int findxor(int a)
{
    if(p[a]==a)
        return 0;
    return findxor(p[a])^x[a];
}
vector<pair<int,int> > bck;
void merge(int a,int b,int xo)
{
    int x1=findxor(a);
    int x2=findxor(b);
    a=find(a);
    b=find(b);
    if(r[a]>r[b])
        swap(a,b);
    p[a]=b;
    x[a]=x1^x2^xo;
    int t=0;
    if(r[a]==r[b])
        r[b]++,t++;
    bck.pb({a,t});
}
void undo()
{
    int a=bck.back().f;
    int t=bck.back().s;
    bck.pop_back();
    if(t)
        r[p[a]]--;
    p[a]=a;
    x[a]=0;
}
vector<int> gaus(31);
vector<int> un;
void addgaus(int x)
{
    for(int i=30;i>=0;i--)
    {
        if(x&(1<<i))
        {
            if(!gaus[i])
            {
                gaus[i]=x;
                un.pb(i);
                return;
            }
            x^=gaus[i];
        }
    }
    un.pb(-1);
}
void undogaus()
{
    int tr=un.back();
    un.pop_back();
    if(tr!=-1)
        gaus[tr]=0;
}
map<int,pair<int,int>> mapa[N];
vector<pair<int,int> > qu(N);
vector<int> sol(N);
struct segTree{
    vector<vector<pair<int,pair<int,int> > > > edges;
    segTree()
    {
        edges.resize(4*N);
    }
    void add(int qs,int qe,pair<int,pair<int,int> > e,int l=0,int r=N-1,int i=1)
    {
        if(qe<l||qs>r)
            return;
        if(qs<=l&&qe>=r)
        {
            edges[i].pb(e);
            return;
        }
        int m=(l+r)>>1;
        add(qs,qe,e,l,m,2*i);
        add(qs,qe,e,m+1,r,2*i+1);
    }
    void answer(int lim,int l=0,int r=N-1,int i=1)
    {
        if(l>lim)
            return;
        //printf("Usao za %i %i %i\n",l,r,i);
        int cnt1=0,cnt2=0;
        for(auto p:edges[i])
        {
            int x=p.f,y=p.s.f,d=p.s.s;
            //printf("Dodajem %i %i %i\n",x,y,d);
            if(find(x)!=find(y))
            {
                //printf("MERGE!\n");
                merge(x,y,d);
                cnt1++;
                continue;
            }
            int xx=findxor(x)^findxor(y)^d;
            //printf("%i\n",xx);
            addgaus(xx);
            cnt2++;
        }
        if(l==r)
        {
            int xx=findxor(qu[l].f)^findxor(qu[l].s);
            for(int i=30;i>=0;i--)
            {
                xx=min(xx,xx^gaus[i]);
            }
            sol[l]=xx;
        }
        else
        {
            int m=(l+r)>>1;
            answer(lim,l,m,2*i);
            answer(lim,m+1,r,2*i+1);
        }
        while(cnt1--)
            undo();
        while(cnt2--)
            undogaus();
    }
}st;
int main()
{
    inittt();
	int n,m;
	scanf("%i %i",&n,&m);
	vector<pair<int,int> > added;
	for(int i=0;i<m;i++)
    {
        int a,b,d;
        scanf("%i %i %i",&a,&b,&d);
        a--;
        b--;
        mapa[a][b]={0,d};
        added.pb({a,b});
    }
    int cnt=0;
    int q;
    scanf("%i",&q);
    for(int i=0;i<q;i++)
    {
        int t,x,y;
        scanf("%i %i %i",&t,&x,&y);
        x--;
        y--;
        if(t==1)
        {
            int d;
            scanf("%i",&d);
            mapa[x][y]={cnt,d};
            added.pb({x,y});
        }
        if(t==2)
        {
            if(mapa[x][y].f<cnt)
                st.add(mapa[x][y].f,cnt-1,{x,{y,mapa[x][y].s}});
            mapa[x][y]={-1,-1};
        }
        if(t==3)
        {
            qu[cnt]={x,y};
            cnt++;
        }
    }
    //printf("DONE!\n");
    for(auto p:added)
        if(mapa[p.f][p.s].f!=-1)
            st.add(mapa[p.f][p.s].f,cnt-1,{p.f,{p.s,mapa[p.f][p.s].s}});
    st.answer(cnt-1);
    for(int i=0;i<cnt;i++)
        printf("%i\n",sol[i]);
    return 0;
}