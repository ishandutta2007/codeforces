#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200020;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
int n,m,k,a[maxn],y[maxn],cur;
ll pre[2020],dp[2020];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,n) scanf("%d",a+i);
	FOR(i,1,m){
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		y[xx]=max(y[xx],yy);
	}
	sort(a+1,a+n+1);
	FOR(i,1,k) pre[i]=pre[i-1]+a[i];
	MEM(dp,0x3f);
	dp[0]=0;
	FOR(i,1,k){
		FOR(j,1,i) dp[i]=min(dp[i],dp[i-j]+pre[i]-pre[i-j+y[j]]);
	}
	cout<<dp[k];
}
// orz CDW SCOI AK