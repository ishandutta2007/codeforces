/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
struct seg
{
    int val[4000001];
    void reset(int c, int l, int r)
    {
        val[c]=0;
        if (l<r)
        {
            int mid=(l+r)/2;
            reset((c<<1),l,mid);
            reset((c<<1)+1,mid+1,r);
        }
    }
    void update(int c, int l, int r, int t, int d)
    {
   //     if (c==1) cout<<"upd "<<t<< ' '<<d<<endl;
        if ((l<=t)and(t<=r))
        {
            val[c]+=d;
            if (l<r)
            {
                int mid=(l+r)/2;
                update((c<<1),l,mid,t,d);
                update((c<<1)+1,mid+1,r,t,d);
            }
        }
    }
    int get(int c, int l, int r, int tl, int tr)
    {
    //    if (c==1) cout<<"get "<<tl<< ' '<<tr<<endl;
        if ((tl>r)or(tr<l)) return 0;
        if ((tl<=l)and(tr>=r)) return val[c];
        else
        {
            int mid=(l+r)/2;
            int a=get((c<<1),l,mid,tl,tr);
            int aa=get((c<<1)+1,mid+1,r,tl,tr);
            return a+aa;
        }
    }
};
seg st;
/////////////////////////////////
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
vector<pair<int,char>> gt[400001];
vector<int> req[400001];
/////////////////////////////////
int acnode[400001][26],cnt=1;
int par[400001];
int suff[400001];
int l[400001],r[400001];
vector<int> suffgt[400001];
int nodecnt=1;
/////////////////////////////////
int tar[400001];
int strnode[400001];
int res[400001];
string str[400001];
/////////////////////////////////
void dfs(int x)
{
//    cout<<"dfs "<<x<<endl;
    t++;
    l[x]=t;
    for (auto g : suffgt[x])
    {
        dfs(g);
    }
    r[x]=t;
}
void calc(int x1, int x2)
{
  //  cout<<x1<<' '<<x2<<endl;
    st.update(1,1,cnt,l[x2],1);
    for (auto g : req[x1])
    {
   //     cout<<"proc "<<g<<endl;
        res[g]=st.get(1,1,cnt,l[strnode[g]],r[strnode[g]]);
    }
    for (auto g : gt[x1])
    {
        int u=x2;
        if (acnode[x2][g.se-97]==-1) calc(g.fi,0);
        else calc(g.fi,acnode[x2][g.se-97]);
    }
    st.update(1,1,cnt,l[x2],-1);
}
int main()
{
	fio;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>u;
        if (u==1)
        {
            char c;
            cin>>c;
            gt[0].push_back({i,c});
        }
        else
        {
            char c;
            cin>>j>>c;
            gt[j].push_back({i,c});
        }
    }
    cin>>m;
    par[0]=0;
    suff[0]=0;
    for (i=0;i<26;i++) acnode[0][i]=-1;
    for (j=1;j<=m;j++)
    {
        cin>>tar[j]>>str[j];
        req[tar[j]].push_back(j);
        u=0;
    //    cout<<j<<' '<<tar[j]<<' '<<str[j]<<endl;
        for (auto g : str[j])
        {
            a=g-97;
            if (acnode[u][a]==-1)
            {
            //    cout<<u<<' '<<cnt<<' '<<g<<endl;
                for (i=0;i<26;i++) acnode[cnt][i]=-1;
                par[cnt]=u;
                acnode[u][a]=cnt;
                u=cnt;
                cnt++;
            }
            else
            {
                u=acnode[u][a];
            }
        }
        strnode[j]=u;
    }
    vector<int> bruh;
    bruh.push_back(0);
    for (i=0;i<bruh.size();i++)
    {
        u=bruh[i];
        v=suff[par[u]];
        if (i)
        {
        for (a=0;a<26;a++) if (acnode[par[u]][a]==u) break;
     //   cout<<"proc" <<u<<' '<<v<<' '<<a<<endl;
        if (par[u])
        {
            while(true)
            {
                if (v==0)
                {
                    if (acnode[v][a]==-1) suff[u]=v;
                    else suff[u]=acnode[v][a];
                
                break;
                }
                else
                {
                    if (acnode[v][a]==-1) v=suff[v];
                    else
                    {
                        suff[u]=acnode[v][a];
                        break;
                    }
                }
            }
        }
        else suff[u]=v;
        }
     //   cout<<u<<' '<<suff[u]<<endl;
        if (i) suffgt[suff[u]].push_back(u);
        for (a=0;a<26;a++) if (acnode[u][a]>-1) bruh.push_back(acnode[u][a]);
        for (a=0;a<26;a++) if ((acnode[u][a]==-1)and(acnode[suff[u]][a]>-1)) acnode[u][a]=acnode[suff[u]][a];
    }
    
    dfs(0);
    
    for (i=0;i<cnt;i++)
    {
     //   cout<<"suffgt "<<i<<endl;
    //    for (auto g : suffgt[i]) cout<<g<<' ';
     //   cout<<endl;
    //    cout<<"lr "<<i<<' '<<l[i]<<' '<<r[i]<<endl;
    }
    st.reset(1,1,cnt);
    calc(0,0);
    for (i=1;i<=m;i++) cout<<res[i]<<endl;
    /**/
}