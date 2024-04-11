
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
#define M 300005
int A[M],pos[M],To[M];
int n;
int mx[M][20],LG2[M];
void Init_ST(){
	for(int i=1;i<=n;i++)mx[i][0]=A[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=2;i<=n;i++)LG2[i]=LG2[i>>1]+1;
}
int Get_mx(int L,int R){
	int K=LG2[R-L+1];
	//printf("@%d %d %d %d\n",L,L+(1<<K)-1,R-(1<<K)+1,R);
	return max(mx[L][K],mx[R-(1<<K)+1][K]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	Init_ST();
	To[n+1]=n+1;
	for(int i=1;i<=n;i++)pos[i]=n+1;
	for(int i=n;i>=1;i--){
		To[i]=min(To[i+1],pos[A[i]]);
		pos[A[i]]=i;
	}
	//for(int i=1;i<=n;i++)printf("%d ",To[i]);puts("");
	int ans=0;
	for(int L=1;L<=n;L++){
		//if(A[L]!=1)continue;
		int R=L;
		while(R<To[L]){
			//printf("%d %d %d\n",L,R,To[L]);
			int flag=Get_mx(L,R);
			//printf("flag=%d\n",flag);
			//ans+=flag==(R-L+1);
			if(flag==R-L+1){
				ans++;R++;
			}else R=L+flag-1;
			//printf("L=%d R=%d\n",L,R);
		}
	}
	printf("%d\n",ans);
	return 0;
}