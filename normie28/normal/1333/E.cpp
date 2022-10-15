
// Problem : F. Vicky's Delivery Service
// Contest : Codeforces - Codeforces Round #561 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1166/F
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
int main(){
	int n;
	cin>>n;
	if(n<=2){
		cout<<"-1"<<endl;
		return 0;
	}
	int k = 1, ctr= 0;
	int a[n+1][n+1];
	for(int i = 1; i<=n; i++){
		if(ctr == 0){
			for(int j = 4; j<=n; j++){
				a[i][j] = k++;
			}
			ctr=1;
		}
		else{
			for(int j = n; j>=4; j--){
				a[i][j]= k++;
			}
			ctr= 0;
		}
	}
	ctr= 0;
	for(int j= 3; j>=1; j--){
		if(ctr== 0){
			for(int i = n; i>=4; i--){
				a[i][j] = k++;
			}
			ctr= 1;
		}
		else{
			for(int i = 4; i<=n; i++){
				a[i][j] = k++;
			}
			ctr= 0;
		}
	}
	a[1][1] = n*n - 8;
	a[1][2] = n*n - 1;
	a[1][3] = n*n - 6;
	a[2][1] = n*n - 4;
	a[2][2] = n*n - 7;
	a[2][3] = n*n - 5;
	a[3][1] = n*n ;
	a[3][2] = n*n - 2;
	a[3][3] = n*n - 3;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}