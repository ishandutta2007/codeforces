#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fa[100010];
int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),k=gi(),x,y,ans=0;
	for(int i=1;i<=n;++i)fa[i]=i;
	while(k--){
		x=gi(),y=gi();
		if(hd(x)==hd(y))++ans;
		else fa[hd(x)]=hd(y);
	}
	printf("%d\n",ans);
	return 0;
}