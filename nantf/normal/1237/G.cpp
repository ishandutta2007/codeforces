#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,k,a[maxn],to[20][maxn],avg,ans=1e9,id,pre[maxn];
map<int,int> mp[maxn];
inline int dv(int x){return x?(x-1)/(k-1)+1:0;}
inline int qmo(int x){return (x+n)%n;}
inline void cov(int x,int v){a[qmo(x)]=a[qmo(x)+n]=v,printf("%d ",v+avg);}
void solve(int l,int r,int res){
	if(l==r) return;
//	printf("solve %d %d %d\n",l,r,res);
	if(l+k-1>=r){
		printf("%d ",qmo(l));
		cov(l,res);
		FOR(i,l+1,r) cov(i,0);
		FOR(i,r+1,l+k-1) cov(i,a[i]);
		puts("");
		return;
	}
	int sum=0;
	FOR(i,l,l+k-1) sum+=a[i];
//	printf("sum=%d\n",sum);
	if(sum>=res){
		printf("%d ",qmo(l));
		cov(l,res);
		FOR(i,l+1,l+k-2) cov(i,0);
		cov(l+k-1,sum-res);
		puts("");
		solve(l+k-1,r,0);
	}
	else{
		solve(l+k-1,r,a[l+k-1]+res-sum);
		sum=0;
		FOR(i,l,l+k-1) sum+=a[i];
		printf("%d ",qmo(l));
		cov(l,res);
		FOR(i,l+1,l+k-2) cov(i,0);
		cov(l+k-1,sum-res);
		puts("");
	}
}
int main(){
	n=read();k=read();
	FOR(i,0,n-1) avg+=a[i]=read();
	avg/=n;
	FOR(i,0,n-1) a[i+n]=a[i]-=avg;
	pre[0]=a[0];
	FOR(i,1,2*n-1) pre[i]=pre[i-1]+a[i];
//	FOR(i,0,2*n-1) printf("%d ",a[i]);
//	puts("");
	ROF(i,2*n-1,0){
		to[0][i]=mp[(i+1)%(k-1)].count(pre[i])?mp[(i+1)%(k-1)][pre[i]]:-1;
		mp[i%(k-1)][pre[i]]=i;
	}
	FOR(i,1,19) FOR(j,0,2*n-1) to[i][j]=~to[i-1][j]?to[i-1][to[i-1][j]]:-1;
	FOR(i,0,n-1){
		int at=i,cnt=0;
		ROF(j,19,0) if(~to[j][at] && to[j][at]<i+n) cnt+=1<<j,at=to[j][at];
		int tmp=(at-i-cnt)/(k-1)+dv(i+n-at-1);
		if(tmp<ans) ans=tmp,id=i;
	}
	printf("%d\n",ans);
	int lst=id;
	FOR(i,id+1,id+n-1) if((i-lst-1)%(k-1)==0 && pre[i]==pre[lst]) solve(lst+1,i,0),lst=i;
	solve(lst+1,id+n,0);
}
/*
3 2
40 63 5
*/