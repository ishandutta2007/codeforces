#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,r1,r2,r3,d,a[maxn];
ll f[maxn][2],ans=1e18;
inline ll w0(int i){return 1ll*r1*a[i]+r3;}
inline ll w1(int i){return min((ll)r2,1ll*r1*(a[i]+1));}
int main(){
	n=read();r1=read();r2=read();r3=read();d=read();
	FOR(i,1,n) a[i]=read();
	MEM(f,0x3f);
	f[1][0]=w0(1);f[1][1]=w1(1);
//	printf("f[1][0]=%lld,f[1][1]=%lld\n",f[1][0],f[1][1]);
	FOR(i,2,n-1){
		f[i][0]=min(f[i][0],f[i-1][0]+d+w0(i));
		f[i][0]=min(f[i][0],f[i-1][1]+d+w0(i)+d+r1+d);
		f[i][1]=min(f[i][1],f[i-1][0]+d+w1(i));
		f[i][0]=min(f[i][0],f[i-1][1]+d+w1(i)+d+r1+d+r1);
//		printf("f[%d][0]=%lld,f[%d][1]=%lld\n",i,f[i][0],i,f[i][1]);
	}
	ans=min(ans,f[n-1][0]+d+w0(n));
	ans=min(ans,f[n-1][1]+d+w0(n)+d+r1);
	ans=min(ans,f[n-1][0]+d+w1(n)+d+d+r1);
	ans=min(ans,f[n-1][1]+d+w1(n)+d+r1+d+r1);
	printf("%lld\n",ans);
}