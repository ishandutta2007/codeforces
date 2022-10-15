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

//---------END-------//
int n;
const int N = 5e3+10;
int rep[N];
 
vector<int>getPrimes(int mx){
    vector<int>res;
    bool pr[mx+1];
    memset(pr,0,sizeof pr);
    for(int i=2 ;i <=mx; i ++){
        if(pr[i])continue;
        for(int j=i+i ;j <=mx; j +=i)
            pr[j] = 1;
        res.push_back(i);
    }
    return res;
}
 
vector<short>prim[N];
 
void init(){
    vector<int>primes = getPrimes(N-1);
 
    for(int i=0 ; i<N ;i ++){
        for(int j=0 ; j < primes.size() ;  j++){
            if(primes[j]  > i)break;
 
            int pw = primes[j];
            while(pw <= i){
                int nm = i/pw;
 
                pw *= primes[j];
                while(nm--)
                    prim[i].push_back(j);
            }
        }
        reverse(prim[i].begin(),prim[i].end());
    }
}
 
ll dp[32684654];
int nm[32684654];
 
void dfs(int l,int r,int lev){
    static int in = 0;
    int ind = in;
    in++;
 
    for(int i = l ; i <=r ; ){
        if(lev >= prim[i].size()){
            nm[ind] += rep[i];
            i++;
            continue;
        }
 
        int j = i;
        for( ;  j<=r ; j++){
            if(prim[i][lev] != prim[j][lev])break;
        }
        int te = in;
        dfs(i,j-1,lev+1);
        nm[ind] += nm[te];
        dp[ind] += dp[te] + nm[te];
        i = j;
    }
}
 
ll res = 1e18;
 
void dfs1(int l,int r,int lev,ll dp1=0,int nm1=0){
    static int in = 0;
    dp1 += nm1;
 
    res = min(res,dp[in]+dp1);
 
    int ind = in;
    in++;
    for(int i = l ; i <=r ; ){
        if(lev >= prim[i].size()){
            i++;
            continue;
        }
 
        int j = i;
        for( ;  j<=r ; j++){
            if(prim[i][lev] != prim[j][lev])break;
        }
        int te = in;
        dfs1(i,j-1,lev+1,dp1+dp[ind] - dp[te] - nm[te],nm1+nm[ind] - nm[te]);
        i = j;
    }
}
 
int main(){
    fio;
    cin>>n;
    int k;
    for(int i=0 ;i <n ;i ++){
        cin>>k;
        rep[k]++;
    }
    init();
    dfs(0,5e3,0);
    dfs1(0,5e3,0);
    cout<<res<<endl;
}