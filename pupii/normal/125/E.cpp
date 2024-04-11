#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct edge{int a,b,i;double c;}E[100010],A[100010];
bool operator<(const edge&a,const edge&b){return a.c<b.c;}
int fa[5010],sz[5010];
bool yes[100010];
int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
void Union(int x,int y){
	x=hd(x),y=hd(y);
	if(sz[x]>sz[y])std::swap(x,y);
	fa[x]=y;sz[y]+=sz[x];
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),K=gi();
	for(int i=1;i<=m;++i){
		E[i].a=gi(),E[i].b=gi(),E[i].c=gi();E[i].i=i;
		if(E[i].a>E[i].b)std::swap(E[i].a,E[i].b);
	}
	for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;++i)A[i]=E[i],A[i].c-=1000000*(A[i].a==1);
	std::sort(A+1,A+m+1);int cnt=0;
	for(int i=1,a,b,c;i<=m;++i){
		a=A[i].a,b=A[i].b,c=A[i].c;
		if(hd(a)==hd(b)){yes[i]=0;continue;}
		cnt+=A[i].a==1;Union(a,b);
	}
	if(cnt<K||(n>1&&!K))return puts("-1"),0;
	for(int i=1;i<=n;++i)if(hd(i)!=hd(1))return puts("-1"),0;
	double l=-1e5,r=1e5,mid;
	while(r-l>1e-8){
		mid=(l+r)*0.5;
		for(int i=1;i<=m;++i){
			A[i]=E[i];
			if(A[i].a==1)A[i].c-=mid;
		}
		std::sort(A+1,A+m+1);
		for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
		cnt=0;
		for(int i=1,a,b,c;i<=m;++i){
			a=A[i].a,b=A[i].b,c=A[i].c;
			if(hd(a)==hd(b)){yes[i]=0;continue;}
			cnt+=A[i].a==1;Union(a,b);yes[i]=1;
		}
		cnt<K?(l=mid):(r=mid);
	}
	if(cnt!=K){
		l=(l+r)*0.5+1e-6;
		for(int i=1;i<=m;++i){
			A[i]=E[i];
			if(A[i].a==1)A[i].c-=l;
		}
		std::sort(A+1,A+m+1);
		for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
		cnt=0;
		for(int i=1,a,b,c;i<=m;++i){
			a=A[i].a,b=A[i].b,c=A[i].c;
			if(hd(a)==hd(b)||(a==1&&cnt==K)){yes[i]=0;continue;}
			cnt+=A[i].a==1;Union(a,b);yes[i]=1;
		}
	}
	assert(cnt==K);
	printf("%d\n",n-1);
	for(int i=1;i<=m;++i)if(yes[i])printf("%d ",A[i].i);
	return 0;
}