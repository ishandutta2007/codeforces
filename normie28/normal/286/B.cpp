/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for (ll i = a ; i <= b ; i ++ )
#define rer(i,a,b) for (ll i = a ; i >= b ; i -- )
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "billboard.inp"
#define FILE_OUT "billboard.out"
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
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define bi BigInt
#define pi 3.1415926535897
typedef long long ll;
//------------xc xch normie tm muoi tm phan tram no----------//
int n,po,i,j;
int arr[2000001];
int main() {
    cin>>n;
    for (i=1;i<=n;i++) arr[i]=i;
    po=1;
    for (int k=2;k<=n;k++)
    {
        for (i=ceil((double(n)/k))-1;i>=0;i--)
        {
            if (i==ceil((double(n)/k))-1) arr[po+n]=arr[po+k*i];
            else arr[po+k*(i+1)]=arr[po+k*i];
        }
            po++;
    }
    for (i=0;i<n;i++) cout<<arr[po+i]<<' ';
}