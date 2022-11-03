// yybakioi
#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int x[100010],y[100010];
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	int n=gi(),k=gi(),ans=0,a;
	for(int i=1;i<=n;++i)x[i]=k+1;
	for(int i=1;i<=k;++i)a=gi(),x[a]=std::min(x[a],i),y[a]=std::max(y[a],i);
	for(int i=1;i<=n;++i)ans+=!y[i];
	for(int i=1;i<n;++i)if(x[i]-y[i+1]>=0)ans++;
	for(int i=1;i<n;++i)if(x[i+1]-y[i]>=0)ans++;
	printf("%d\n",ans);
	return 0;
}