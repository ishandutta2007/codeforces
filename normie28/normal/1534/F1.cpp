#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.4
	Changes:
    Added include-guards to help with writing in multiple source files.
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
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
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
#endif
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
vector<int> col[400001];
vector<int> gt[400001],gt2[400001];
int inn[400001];
int reg[400001];
int degi[400001];
void dfs(int x)
{
    reg[x]=1;
    for (auto g : gt[x]) if (!reg[g]) dfs(g);
    vec.push_back(x);
}
void dfs2(int x)
{
    reg[x]=t;
    for (auto g : gt2[x]) if (!reg[g]) dfs2(g);
}
int main()
{
	fio;
    cin>>n>>m;
    for (i=0;i<n;i++) for (j=0;j<m;j++) 
    {
        char c;
        cin>>c;
        if (c=='#')
        {
            inn[i*m+j]=1;
            col[j].push_back(i);
        }
    }
    for (i=0;i<m;i++) for (j=0;j<col[i].size();j++)
    {
        if (i>0)
        {
            auto it=lower_bound(col[i-1].begin(),col[i-1].end(),col[i][j]);
            if (it!=col[i-1].end())
            {
                gt[col[i][j]*m+i].push_back((*it)*m+(i-1));
            }
        }
        if (i<m-1)
        {
            auto it=lower_bound(col[i+1].begin(),col[i+1].end(),col[i][j]);
            if (it!=col[i+1].end())
            {
                gt[col[i][j]*m+i].push_back((*it)*m+(i+1));
            }
        }
        if (j+1<col[i].size()) gt[col[i][j]*m+i].push_back(col[i][j+1]*m+i);
        if ((j-1>=0)and(col[i][j-1]==col[i][j]-1))
        {
        gt[col[i][j]*m+i].push_back(col[i][j-1]*m+i);
        }
    }
    for (i=0;i<m*n;i++) if ((inn[i]))
    {

        for (auto g : gt[i]) 
        {
        gt2[g].push_back(i);
        //cout<<i/m<<' '<<i%m<<' '<<g/m<<' '<<g%m<<endl;
        }
        if (!reg[i]) dfs(i);
    }
    for (i=0;i<m*n;i++) reg[i]=0;
    while(vec.size())
    {
        if (!reg[vec.back()])
        {
            t++;
            dfs2(vec.back());
        }
        vec.pop_back();
    }
    for (i=0;i<m*n;i++) for (auto g : gt[i]) if (reg[g]-reg[i]) degi[reg[g]]=1;
    for (i=1;i<=t;i++) if (!degi[i]) a++;
    cout<<a;
}