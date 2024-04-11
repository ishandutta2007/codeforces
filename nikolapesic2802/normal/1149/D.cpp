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
const int N=71;
vector<int> par(N);
vector<vector<pair<int,int> > > graf(N);
int find(int a)
{
    if(par[a]==a)
        return a;
    return par[a]=find(par[a]);
}
void merge(int a,int b)
{
    a=find(a);
    b=find(b);
    par[a]=b;
}
int in_component[N][N];
struct ab{
    int dist=INT_MAX;
};
int main()
{
    for(int i=0;i<N;i++)
        par[i]=i;
	int n,m,A,B;
	scanf("%i %i %i %i",&n,&m,&A,&B);
	vector<pair<int,int> > add;
	for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%i %i %i",&a,&b,&c);
        a--;b--;
        if(c==A)
        {
            graf[a].pb({b,c});
            graf[b].pb({a,c});
        }
        else
            add.pb({a,b});
        if(c==A)
            merge(a,b);
    }
    for(auto p:add)
    {
        int a=find(p.f),b=find(p.s);
        if(a!=b)
            graf[p.f].pb({p.s,B}),graf[p.s].pb({p.f,B});
    }
    vector<int> siz(n);
    for(int i=0;i<n;i++)
        siz[find(i)]++;
    vector<int> ind(n);
    int tr=0;
    for(int i=0;i<n;i++)
        if(siz[i]>3)
            ind[i]=tr++;
        else
            ind[i]=-1;
    gp_hash_table<int,ab> d[N];
    int mask=0;
    if(ind[find(0)]!=-1)
        mask|=(1<<ind[find(0)]);
    set<pair<int,pair<int,int> > > q;
    q.insert({0,{0,mask}});
    vector<int> best(n,INT_MAX/2);
    vector<int> bio(n);
    int z=0;
    while(q.size())
    {
        auto tr=*q.begin();
        q.erase(q.begin());
        if(tr.f>=2*best[tr.s.f])
            continue;
        if(d[tr.s.f][tr.s.s].dist<tr.f)
            continue;
        best[tr.s.f]=min(best[tr.s.f],tr.f);
        /*if(!bio[tr.s.f])
            bio[tr.s.f]=1,z++;
        if(z==n)
            break;*/
        for(auto p:graf[tr.s.f])
        {
            if(p.s==A)
            {
                if(d[p.f][tr.s.s].dist>tr.f+A)
                {
                    d[p.f][tr.s.s].dist=tr.f+A;
                    q.insert({tr.f+A,{p.f,tr.s.s}});
                }
            }

        }
        for(auto p:graf[tr.s.f])
        {
            if(p.s==B)
            {
                int m=ind[find(p.f)];
                if(m!=-1)
                    if(tr.s.s&(1<<m))
                        continue;
                if(d[p.f][tr.s.s|(1<<m)].dist>tr.f+B)
                {
                    d[p.f][tr.s.s|(1<<m)].dist=tr.f+B;
                    q.insert({tr.f+B,{p.f,tr.s.s|(1<<m)}});
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%i ",best[i]);
    return 0;
}