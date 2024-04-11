
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
int a[11][11];
double f[11][11];
int cal(int x,int y){
	return (x-1)*10+((x&1)?y:10-y+1);
}
int recal(int x){
	int y=(x-1)/10+1;
	return y*100+((y&1)?(x-1)%10+1:10-(x-1)%10);
}
double C(int x,int y){
	return min(f[x][y],f[x-a[x][y]][y]);
}
int main(){
	for(int i=1;i<=10;i++)for(int j=1;j<=10;j++)scanf("%d",a[i]+j);
	for(int i=1;i<=10;i++){
		if(i&1)for(int j=1,x;j<=10;j++){
			if(i==7)
			i=7;
			if((x=cal(i,j))<=6){
				if(j!=1)f[i][j]=6;
			}
			else{
//				f[i][j]=1;
				for(int k=1;k<=6;k++){
					int x1=recal(x-k)/100,y1=recal(x-k)%100;
					f[i][j]+=(C(x1,y1)+1)/6;
				}
			}
		}
		else for(int j=10,x;j>=1;j--){
			x=cal(i,j);f[i][j]=1;
			for(int k=1;k<=6;k++){
				int x1=recal(x-k)/100,y1=recal(x-k)%100;
				f[i][j]+=(C(x1,y1))/6;
			}
		}
	}
	printf("%.10lf",f[10][1]);
	return 0;
}