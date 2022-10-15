
// Problem : F. Bicolored Segments
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1389/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//----------NMFF0B0H----------//
#include <bits/stdc++.h>
#define IM using
#define GAY namespace
#define LOL std;
IM GAY LOL
/*
Search the term 'algorithm visualization' in your favorite Search Engine, do you see VisuAlgo in the first page of the search result :)? Next level: Search that term again, but in your native language (if it is not English). Is VisuAlgo still listed in the first page? :). And get ready to be surprised: Search the name of your favorite data structure or algorithm without mentioning the keyword 'animation' or 'visualization'. Is VisuAlgo still listed in the first page? :):).
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define FILE_IN "caps.inp"
#define FILE_OUT "caps.out"
#define ofile                     \
    freopen(FILE_IN, "r", stdin); \
    freopen(FILE_OUT, "w", stdout)
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define nfio    \
    cin.tie(0); \
    cout.tie(0)
#define ord(a, b, c) ((a >= b) and (b >= c))
#define MOD (ll(18101203))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1) << x)
#define pii pair<int, int>
#define piii pair<int, pii>
#define For(i, __, ___) for (int i = __; i <= ___; i++)
#define Rep(i, __, ___) for (int i = __; i >= ___; i--)
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
#define endl "\n"
#define vi vector<int>
#define bi bigint
#define get geet
#define pll pair<ll,ll>
#define list_of_primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}
typedef long long ll; 
const long long inf=1e18;
 
struct str
{
    int nod1,nod2;
    long long c;
};
 
struct edge
{
    int nod;
    long long cost;
    bool operator <(const edge &aux) const
    {
        return cost>aux.cost;
    }
};
 
vector<str> edges;
vector<edge> v[100010];
vector<int> qry[100010];
priority_queue<edge> q1;
long long dist[100010],res[300010];
int rad[100010],cnt[100010];
pair<int,int> nodes[300010];
 
int cmp(str a,str b)
{
    return a.c<b.c;
}
 
int root(int x)
{
    int y=x;
    while(y!=rad[y]) y=rad[y];
    while(x!=y)
    {
        int aux=rad[x];
        rad[x]=y;
        x=aux;
    }
    return y;
}
 
int main()
{
    fio;
    int n,m,k,q,x,y;
    long long c;
    cin>>n>>m>>k>>q;
    for(int i=1;i<=n;i++)
    {
        dist[i]=inf;
        rad[i]=i;
        cnt[i]=1;
        if(i<=k) {q1.push({i,0});dist[i]=0;}
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>c;
        v[x].push_back({y,c});
        v[y].push_back({x,c});
    }
    while(!q1.empty())
    {
        int nod=q1.top().nod;
        long long cost=q1.top().cost;
        q1.pop();
        if(cost>dist[nod]) continue;
        for(int i=0;i<v[nod].size();i++)
        {
            int vec=v[nod][i].nod;
            c=v[nod][i].cost;
            if(cost+c<dist[vec])
            {
                dist[vec]=cost+c;
                q1.push({vec,dist[vec]});
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<v[i].size();j++)
        {
            int vec=v[i][j].nod;
            c=v[i][j].cost;
            edges.push_back({i,vec,c+dist[vec]+dist[i]});
        }
    sort(edges.begin(),edges.end(),cmp);
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        qry[x].push_back(i);
        qry[y].push_back(i);
        nodes[i]={x,y};
        res[i]=inf;
    }
    for(int i=0;i<edges.size();i++)
    {
        int nod1=edges[i].nod1,nod2=edges[i].nod2;
        c=edges[i].c;
        x=root(nod1);y=root(nod2);
        if(x==y) continue;
        if(cnt[x]>cnt[y]) swap(x,y);
        rad[x]=y;
        cnt[y]+=cnt[x];
        for(int j=0;j<qry[x].size();j++)
        {
            int pz=qry[x][j];
            if(root(nodes[pz].first)==root(nodes[pz].second)) res[pz]=min(c,res[pz]);
            else qry[y].push_back(pz);
        }
    }
    for(int i=1;i<=q;i++) cout<<res[i]<<endl;
}