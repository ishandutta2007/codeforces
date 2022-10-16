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
struct segTree{
    vector<int> lazy;
    void init()
    {
        lazy.resize(4*N);
    }
    void add(int qs,int qe,int val,int l=0,int r=N-1,int i=1)
    {
        if(qs>qe)
            return;
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {
            lazy[i]+=val;
            return;
        }
        lazy[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
        lazy[i]=0;
        int m=(l+r)>>1;
        add(qs,qe,val,l,m,2*i);
        add(qs,qe,val,m+1,r,2*i+1);
    }
    int get(int pos,int l=0,int r=N-1,int i=1)
    {
        if(l>pos||r<pos)
            return 0;
        if(l==pos&&r==pos)
            return lazy[i];
        lazy[2*i]+=lazy[i];
        lazy[2*i+1]+=lazy[i];
        lazy[i]=0;
        int m=(l+r)>>1;
        return get(pos,l,m,2*i)+get(pos,m+1,r,2*i+1);
    }
}even,odd;
vector<vector<int> > graf(N);
vector<int> vall(N),ineven(N),inodd(N),outeven(N),outodd(N),depth(N);
int timeeven,timeodd;
void doit(int tr,int par)
{
    ineven[tr]=timeeven;
    inodd[tr]=timeodd;
    if(depth[tr]%2==0)
        timeeven++;
    else
        timeodd++;
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        depth[p]=depth[tr]+1;
        doit(p,tr);
    }
    outeven[tr]=timeeven-1;
    outodd[tr]=timeodd-1;
}
int main()
{
    even.init();
    odd.init();
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=0;i<n;i++)
        scanf("%i",&vall[i]);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;b--;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    doit(0,-1);
    for(int i=0;i<n;i++)
    {
        if(depth[i]%2==0)
            even.add(ineven[i],ineven[i],vall[i]);
        else
            odd.add(inodd[i],inodd[i],vall[i]);
    }
    for(int i=0;i<m;i++)
    {
        int t;
        scanf("%i",&t);
        if(t==2)
        {
            int a;
            scanf("%i",&a);
            a--;
            if(depth[a]%2==0)
                printf("%i\n",even.get(ineven[a]));
            else
                printf("%i\n",odd.get(inodd[a]));
        }
        else
        {
            int a,val;
            scanf("%i %i",&a,&val);
            a--;
            if(depth[a]%2)
                val*=-1;
            even.add(ineven[a],outeven[a],val);
            val*=-1;
            odd.add(inodd[a],outodd[a],val);
        }
    }
    return 0;
}