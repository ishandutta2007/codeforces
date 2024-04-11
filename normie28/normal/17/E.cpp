
// Problem : E. Palisection
// Contest : Codeforces - Codeforces Beta Round #17
// URL : https://codeforces.com/problemset/problem/17/E
// Memory Limit : 128 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
#define P 51123987
#define maxn 4000005
//---------END-------//
int k,c[501],pos[100001],t,t1,i,j;
int N,M=1,f[maxn],l[maxn],r[maxn],res;
char a[maxn],b[maxn];
 
int main()
{
	fio;
    cin>>N>>a;
    b[0]=1;
    for (int i=0; i<N; i++) b[++M]=a[i],M++;
    for (int i=1,p=0,q=0; i<=M; i++)
    {
        f[i]=q>i?min(f[2*p-i],q-i):1;
        for (;b[i+f[i]]==b[i-f[i]]; f[i]++);
        if (i+f[i]>q) p=i,q=i+f[i];
    }
    for (int i=1; i<=M; i++) l[i-f[i]+1]++,l[i+1]--,r[i]++,r[i+f[i]]--,(res+=f[i]/2)%=P;
    res=1ll*res*(res-1)/2%P;
    for (int i=1,s=0; i<=M; i++)
    {
        l[i]+=l[i-1],r[i]+=r[i-1];
        if (i%2==0) (res-=1ll*s*l[i]%P)%=P,(s+=r[i])%=P;
    }
    cout<<((res+P)%P)<<endl;
}