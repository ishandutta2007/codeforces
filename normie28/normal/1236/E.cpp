
// Problem : E. Alice and the Unfair Game
// Contest : Codeforces - Codeforces Round #593 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1236/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
//---------END-------//
const int N=1e5+9;
map<int,vector<int>>l,r;
int n,m;
int a[N];
int main(){
	fio;
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>a[i];
    if(n==1){
        if(m)cout<<0<<endl;
        else cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)l[i].push_back(i),r[i].push_back(i);
    for(int i=1;i<=m;i++){
        int z=a[i]+i,y=a[i]-i;
        int tz=z+1,ty=y-1;
        if(l[tz].size()<l[z].size())swap(l[tz],l[z]);
        for(auto j:l[z])l[tz].push_back(j);l[z].clear();
        if(r[ty].size()<r[y].size())swap(r[ty],r[y]);
        for(auto j:r[y])r[ty].push_back(j);r[y].clear();
    }
    #define ll long long
    ll res=n;
    for(auto i:l){
        int t=i.first-m-1;
        t=max(t,1);
        res-=1ll*t*i.second.size();
    }
    for(auto i:r){
        int t=i.first+m+1;
        t=min(t,n);
        res+=1ll*t*i.second.size();
    }
    cout<<res<<endl;
}