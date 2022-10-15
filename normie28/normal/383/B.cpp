// Problem: B. Volcanoes
// Contest: Codeforces - Codeforces Round #225 (Div. 1)
// URL: https://codeforces.com/contest/383/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int maxn=2e5+5;
set<pii(ll)>S[2];
vector<int>V[maxn];
pii(ll) e[maxn];
int tmp[maxn<<1],num;
int main(){
    int n,m;
    cin>>n>>m;
    tmp[++num]=1;
    tmp[++num]=2;
    tmp[++num]=n;
    tmp[++num]=n-1;
    for (int i=1;i<=m;i++)
    {
        cin>>e[i].fi>>e[i].se;
        tmp[++num]=min(n,e[i].se),tmp[++num]=min(n,e[i].se+1);
    }
    sort(tmp+1,tmp+1+num);
    num=unique(tmp+1,tmp+1+num)-tmp-1;
    for(int i=1;i<=m;i++)
        e[i].se=lower_bound(tmp+1,tmp+1+num,e[i].se)-tmp,V[e[i].se].push_back(e[i].first);
    for(int i=1;i<=num;i++)
        sort(V[i].begin(),V[i].end());
    if(V[1].size()&&V[1][0]==1)
        return cout<<-1,0;
 
    int f=0;
    if(V[1].size())
        S[f].insert({1,V[1][0]-1});
    else
        S[f].insert({1,n});
    set<pii(ll)>::iterator it;
    for(int i=2;i<=num;i++){
 
        V[i].push_back(n+1);
        for(int j=0;j<V[i].size();j++){
            if(S[f].empty())break;
            it=S[f].begin();
            if((*it).fi>V[i][j])continue;
            int l=(*it).fi,r=V[i][j]-1;
            if(r>=l)S[!f].insert({l,r});
            while(1){
                if(S[f].empty())break;
                it=S[f].begin();
                if((*it).fi>V[i][j])break;
                if((*it).se<=V[i][j])S[f].erase(it);
                else{
                    if((*it).fi>V[i][j])
                        continue;
                    int r=(*it).se;
                    S[f].erase(it);
                    S[f].insert({V[i][j]+1,r});
                    break;
                }
            }
        }
        S[f].clear();
        f=!f;
    }
    int ans=0;
    for(it=S[f].begin();it!=S[f].end();it++){
        if((*it).se==n)ans=1;
    }
    if(ans)cout<<n*2-2;
    else cout<<-1;
}