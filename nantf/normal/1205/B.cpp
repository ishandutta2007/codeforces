#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,maxm=13333333;
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
int n,ans=1e9,dis[1111][1111],cnt[66],hhh[1111];
ll a[maxn];
int main(){
	n=read();
	FOR(i,1,n){
		a[i]=read();
		if(!a[i]){i--;n--;continue;}
		FOR(j,0,60) if((a[i]>>j)&1) cnt[j]++;
	}
	FOR(i,0,60) if(cnt[i]>=3) return puts("3"),0;
	if(!n) return puts("-1"),0;
	MEM(dis,0x3f);
	FOR(i,1,n) dis[i][i]=0;
	FOR(i,1,n) FOR(j,i+1,n) if(a[i]&a[j]){
		ans=min(ans,dis[i][j]+1);
		dis[i][j]=1;
		FOR(k,1,n) FOR(l,k+1,n) dis[k][l]=dis[l][k]=min(dis[k][l],min(dis[k][i]+dis[l][j]+1,dis[k][j]+dis[l][i]+1));
	}
	printf("%d\n",ans>n?-1:ans);
} // Quan Chang Jiu Wo Bu Hui B Xi Lie