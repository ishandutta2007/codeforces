#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
using namespace std;
int n,m,ans;
int a[100005],b[100005],f[100005],g[100005];
int main(){
	scanf("%d%d",&n,&m);
	int x,y; F(i,1,n) scanf("%d%d",&x,&y), ++a[x], --a[y+1];
	F(i,1,m) a[i]+=a[i-1];
	memset(b,0x3f,sizeof b); b[0]=0;
	F(i,1,m){
		f[i]=lower_bound(b,b+m+1,a[i]+1)-b;
		b[f[i]]=min(b[f[i]],a[i]);
	}
	reverse(a+1,a+m+1);
	memset(b,0x3f,sizeof b); b[0]=0;
	F(i,1,m){
		g[i]=lower_bound(b,b+m+1,a[i]+1)-b;
		b[g[i]]=min(b[g[i]],a[i]);
	}
	F(i,1,m) ans=max(ans,f[i]+g[m-i+1]-1);
	printf("%d",ans);
	return 0;
}