#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[513][513],b[513][513],x[111],y[111];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int k=gi(),n=1<<k;
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)a[i][j]=gi();
	int t=gi();
	for(int i=1;i<=t;++i)x[i]=gi(),y[i]=gi();
	for(int qwq=1;qwq<=k;++qwq){
		for(int i=0;i<n;++i)for(int j=0;j<n;++j)for(int o=1;o<=t;++o)b[(i+x[o])%n][(j+y[o])%n]^=a[i][j];
		memcpy(a,b,sizeof a);memset(b,0,sizeof b);
		for(int i=1;i<=t;++i)x[i]=x[i]*2%n,y[i]=y[i]*2%n;
	}
	int ans=0;
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)ans+=!!a[i][j];
	printf("%d\n",ans);
	return 0;
}