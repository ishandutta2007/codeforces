#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int fa[400010],siz[400010];
il int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
int main(){
#ifndef ONLINE_JUDGE
	freopen("5089.in","r",stdin);
	freopen("5089.out","w",stdout);
#endif
	int n=gi(),m=gi(),q=gi(),r,c;
	for(int i=1;i<=n+m;++i)fa[i]=i,siz[i]=1;
	while(q--){
		r=hd(gi()),c=hd(gi()+n);
		if(r^c){
			if(siz[r]>siz[c])siz[r]+=siz[c],fa[c]=r;
			else siz[c]+=siz[r],fa[r]=c;
		}
	}
	int ans=-1;for(int i=1;i<=n+m;++i)ans+=fa[i]==i;
	printf("%d\n",ans);
	return 0;
}