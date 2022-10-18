#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,K,p,v[22222],s[22222],g[55][111],ans;
int main(){
	n=read();K=read();p=read();
	FOR(i,1,n) v[i]=read()%p,s[i]=(s[i-1]+v[i])%p;
	MEM(g,~0x3f);g[0][0]=0;
	FOR(i,1,n) ROF(j,K,1){
		int x=-1e9;
		FOR(k,0,p-1) x=max(x,g[j-1][k]+(s[i]-k+p)%p);
		if(i==n) ans=max(ans,x);
		g[j][s[i]]=max(g[j][s[i]],x);
	}
	printf("%d\n",ans);
}