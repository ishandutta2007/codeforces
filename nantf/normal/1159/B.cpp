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
int n,a[maxn],mn[maxn],mmm=1e9,k=1e9;
int main(){
	MEM(mn,0x3f);
	n=read();
	FOR(i,1,n) a[i]=read();
	mn[n-1]=min(a[1],a[n]);
	ROF(i,n-2,1) mn[i]=min(mn[i+1],min(a[i+1],a[n-i]));
	FOR(i,1,n-1) k=min(k,mn[i]/i);
	printf("%d\n",k);
}