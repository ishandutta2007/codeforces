#include<bits/stdc++.h>
using namespace std;
const int maxn=300030,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int T,n,a[maxn],b[maxn],bl,lft[maxn],rig[maxn];
int main(){
	T=read();
	MEM(lft,0x3f);
	while(T--){
		n=read();
		FOR(i,1,n) b[i]=a[i]=read();
		sort(b+1,b+n+1);bl=unique(b+1,b+n+1)-b-1;
		FOR(i,1,n) a[i]=lower_bound(b+1,b+bl+1,a[i])-b;
		FOR(i,1,n) lft[a[i]]=min(lft[a[i]],i),rig[a[i]]=max(rig[a[i]],i);
		int ans=0;
		FOR(i,1,bl){
			int j=i;
			while(j<bl && rig[j]<lft[j+1]) j++;
			ans=max(ans,j-i+1);
			i=j;
		}
		printf("%d\n",bl-ans);
		FOR(i,1,bl) lft[i]=1e9,rig[i]=0;
	}
} // DDoS