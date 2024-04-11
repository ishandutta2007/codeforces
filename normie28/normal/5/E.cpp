
// Problem : E. Bindian Signalizing
// Contest : Codeforces - Codeforces Beta Round #5
// URL : https://codeforces.com/problemset/problem/5/E
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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
//---------END-------//
int m,k,c[501],pos[100001],t,t1,i,j;
ll n,a[1000005],b[1000005],l[1000005],r[1000005],ff[1000005];
 
int main(){
	fio;
	cin>>n;
	ll maxx=-1e9,maxp; 
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxx){
			maxx=a[i];
			maxp=i;
		}
	}
	for(ll i=0;i<n;i++){
		b[i]=a[(i+maxp-1)%n+1];
	}
	b[n]=a[maxp];
	r[n]=n;
	l[0]=0;
	for(ll i=n-1;i>=0;i--){
		r[i]=i+1;
		while(r[i]<n&&b[i]>b[r[i]]){
			r[i]=r[r[i]];
		}
		if(r[i]<n&&b[i]==b[r[i]]){
			ff[i]=ff[r[i]]+1;
			r[i]=r[r[i]];
		}
	}
	for(ll i=1;i<n;i++){
		l[i]=i-1;
		while(l[i]&&b[i]>=b[l[i]]){
			l[i]=l[l[i]];
		}
	}
	ll res=0;
	for(ll i=1;i<n;i++){
		res+=ff[i];
		if(l[i]!=0||r[i]!=n){
			res+=2;
		}else{
			res++;
		}
	}
	cout<<res<<endl;
}