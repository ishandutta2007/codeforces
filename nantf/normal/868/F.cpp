#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,k,L,R,a[maxn];
ll dp[22][maxn],cnt[maxn],wreturn;
ll w(int l,int r){
	while(L<l) cnt[a[L]]--,wreturn-=cnt[a[L]],L++;
	while(R<r) R++,wreturn+=cnt[a[R]],cnt[a[R]]++;
	while(L>l) L--,wreturn+=cnt[a[L]],cnt[a[L]]++;
	while(R>r) cnt[a[R]]--,wreturn-=cnt[a[R]],R--;
	return wreturn;
}
void solve(int l,int r,int kl,int kr,int id){
	if(l>r) return;
	int mid=(l+r)>>1,kmid=0;
	FOR(i,kl,min(mid,kr)){
		ll val=dp[id-1][i-1]+w(i,mid);
		if(val<dp[id][mid]){
			dp[id][mid]=val;
			kmid=i;
		}
	}
	solve(l,mid-1,kl,kmid,id);
	solve(mid+1,r,kmid,kr,id);
}
int main(){
	n=read();k=read();
	FOR(i,1,n) a[i]=read();
	MEM(dp,0x3f);
	dp[0][0]=0;
	L=1;R=0;
	FOR(i,1,k) solve(1,n,1,n,i);
	printf("%I64d\n",dp[k][n]);
}