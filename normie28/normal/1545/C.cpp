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
vector<int> vec,pic;
int n,m,i,j,k,t,t1,u,v,a,b;
int arr[1001][501],res[1001];
vector<int> buc[501],gt[1001];
void dfs(int x , int p)
{
    res[x]=p;
    for (auto g : gt[x]) if (!res[g]) dfs(g,p*-1);
}
int main()
{
	fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n;
        vec.clear();
        pic.clear();
        for (i=1;i<=2*n;i++) for (j=1;j<=n;j++)
        {
            cin>>arr[i][j];
        }
        for (i=1;i<=2*n;i++)
        {
            vec.push_back(i);
            gt[i].clear();
            res[i]=0;
        }
        for (i=1;i<=n;i++)
        {
            buc[i].clear();
        }
        while(true)
        {
            for (i=1;i<=n;i++)
            {
                for (j=1;j<=n;j++) buc[j].clear();
                for (auto g : vec) buc[arr[g][i]].push_back(g);
                for (j=1;j<=n;j++) if (buc[j].size()==1) break;
                if (j==n+1) continue;
                vec.erase(find(vec.begin(),vec.end(),buc[j][0]));
                res[buc[j][0]]=1;
                for (auto it=vec.begin();it!=vec.end();)
                {
                    for (k=1;k<=n;k++) if (arr[(*it)][k]==arr[buc[j][0]][k])
                    break;
                    if (k<=n) {res[(*it)]=-1; it=vec.erase(it); }
                    else it++;
                }
                break;
            }
            if (i==n+1) break;
        }
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++) buc[j].clear();
            for (auto g : vec) buc[arr[g][i]].push_back(g);
            for (j=1;j<=n;j++) if (buc[j].size()==2) 
            {
                gt[buc[j][0]].push_back(buc[j][1]);
                gt[buc[j][1]].push_back(buc[j][0]);
            }
        }
        u=1;
        for (i=1;i<=2*n;i++) if (!res[i])
        {
            u*=2;
            u%=MOD;
            dfs(i,1);
        }
        cout<<u<<endl;
        for (i=1;i<=2*n;i++) if (res[i]==1) cout<<i<<' '; cout<<endl;
    }
}