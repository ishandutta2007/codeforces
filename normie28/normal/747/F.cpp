
// Problem : F. Igor and Interesting Numbers
// Contest : Codeforces - Codeforces Round #387 (Div. 2)
// URL : https://codeforces.com/contest/747/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	Normie's Template v2.0
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
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
const ll maxn = (20) + 2;
ll k , t , maxi[20] , f[20][maxn] , C[maxn][maxn];
 
char what(ll x)
{
    if(x<=10)
        return '0' + (x - 1);
    else
        return 'a' + (x - 10 - 1);
}
 
void get_res(ll len)
{
    for(ll i=0 ; i<=16 ; i++)
    
    for(ll j=0 ; j<=len ; j++) f[i][j] = 0;
       
    for(ll i=0 ; i<=16 ; i++) f[i][0] = 1;
    
    for(ll i=1 ; i<=16 ; i++) 
    for(ll j=1 ; j<=len ; j++) 
    for(ll k=0 ; k<=maxi[i] && k<=j ; k++)
       f[i][j] += f[i-1][j-k] * C[k][j];
}
 
int main()
{
	fio;
    cin>>k>>t;
    for(ll i=0 ; i<maxn ; i++)
        C[0][i] = C[i][i] = 1;
    for(ll i=1 ; i<maxn ; i++)
        for(ll j=i ; j<maxn ; j++)
            C[i][j] = C[i][j-1] + C[i-1][j-1];
    for(ll i=1 ; i<=16 ; i++)
        maxi[i] = t;
    ll L = 0;
    get_res(20);
    for(L=1 ; L<=20 ; L++){
        ll res = f[16][L];
        res = (res/16)*15;
        if(res>=k)
            break;
        k-=res;
    }
    if(L==1)
        return cout<<what(k+1)<<endl , 0;
    for(ll i=1 ; i<=L ; i++)
    {
        for(ll j=1 ; j<=16 ; j++)
        {
            if(i==1&&j==1)continue;
            if(!maxi[j])continue;
            maxi[j]--;
            get_res(L-i);
            ll res = f[16][L-i];
            if(res>=k){
                cout<<what(j);
                break;
            }
            k -= res;
            maxi[j]++;
        }
    }
}