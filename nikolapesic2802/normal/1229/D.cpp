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

const int K=5,L=120;
int n,k,cnt;
struct Node{
    int val;
    vector<int> nxt;
    Node()
    {
        nxt.resize(K+1,-1);
    }
};
vector<Node> nodes(1);
vector<int> dodajem;
void addPath(int i,int val,int tr)
{
    if(i==k)
    {
        nodes[tr].val=val;
        return;
    }
    int sl=dodajem[i];
    if(nodes[tr].nxt[sl]==-1)
    {
        Node nov;
        nodes.pb(nov);
        nodes[tr].nxt[sl]=nodes.size()-1;
    }
    addPath(i+1,val,nodes[tr].nxt[sl]);
}
int getVal(int i,int tr)
{
    if(i==k)
        return nodes[tr].val;
    return getVal(i+1,nodes[tr].nxt[dodajem[i]]);
}
struct DSU{
    int trsiz;
    vector<int> p,siz;
    void init()
    {
        trsiz=1;
        p.resize(L);
        siz.resize(L);
        for(int i=0;i<L;i++)
            p[i]=i,siz[i]=1;
    }
    int find(int a){return a==p[a]?a:p[a]=find(p[a]);}
    bool moze(int a,int b)
    {
        return find(a)!=find(b);
    }
    void merge(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(siz[a]>siz[b])
            swap(a,b);
        p[a]=b;
        siz[b]+=siz[a];
        trsiz=siz[find(0)];
    }
};
vector<vector<int> > perms;
vector<pair<int,int> > getGrane(vector<int> p)
{
    vector<pair<int,int> > grane;
    int cnt=0;
    for(auto vals:perms)
    {
        dodajem=p;
        for(auto &p:dodajem)
            p=vals[p-1];
        grane.pb({cnt,getVal(0,0)});
        cnt++;
    }
    return grane;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%i %i",&n,&k);
	vector<int> p(k);
	for(int i=0;i<k;i++)
        p[i]=i+1;
    do{
        dodajem=p;
        addPath(0,cnt,0);
        cnt++;
        perms.pb(p);
    }while(next_permutation(all(p)));
    DSU prazan;
    prazan.init();
    vector<pair<DSU,int> > ds;
    ll sol=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
            scanf("%i",&p[j]);
        auto gr=getGrane(p);
        ds.pb({prazan,1});
        for(auto p:gr)
        {
            for(int i=ds.size()-1;i>=0;i--)
                if(!ds[i].f.moze(p.f,p.s))
                    break;
                else
                    ds[i].f.merge(p.f,p.s);
        }
        vector<pair<DSU,int> > novi;
        for(int i=0;i<ds.size();i++)
        {
            if(i!=ds.size()-1&&ds[i].f.trsiz==ds[i+1].f.trsiz)
            {
                ds[i+1].s+=ds[i].s;
                continue;
            }
            novi.pb(ds[i]);
            sol+=(ll)ds[i].f.trsiz*ds[i].s;
        }
        ds=novi;
    }
    printf("%lld\n",sol);
    return 0;
}