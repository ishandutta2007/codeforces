#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
inline int qmo(int x){return x+(x>>31)*mod;}
int n,d,m,a[maxn],b[maxn],bl,c[maxn],cl;
ll sufb[maxn],sufc[maxn],ans;
int main(){
	n=read();d=read();m=read();
	FOR(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	FOR(i,1,n) if(a[i]<=m) b[++bl]=a[i];
	else c[++cl]=a[i];
	ROF(i,bl,1) sufb[i]=sufb[i+1]+b[i];
	ROF(i,cl,1) sufc[i]=sufc[i+1]+c[i];
	FOR(i,0,cl){
		ll tot=max(0ll,1ll*(d+1)*(i-1)+1);
		if(tot>n) break;
		int res=n-tot;
		ans=max(ans,sufb[max(1,bl-res+1)]+sufc[cl-i+1]);
//		printf("i=%d,res=%d\n",i,res);
	} 
	printf("%lld\n",ans);
}