//bybykbykyb
#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fa[100010],siz[100010],same[100010],L[100010];
int askx[100010],asky[100010],k,newx[100010],m,from[100010],lst[100010],p[100010];
char s[100010];
il vd ask(bool t){
	if(!k)return;printf("Q %d ",k);
	if(!t)for(int i=1;i<=k;++i)printf("%d %d ",askx[i],asky[i]);
	else for(int i=1;i<=k;++i)printf("%d %d ",newx[askx[i]],newx[asky[i]]);
	puts("");fflush(stdout);
	scanf("%s",s+1);
	if(!t)for(int i=1;i<=k;++i)same[askx[i]]=s[i]=='1';
	else for(int i=1;i<=k;++i)lst[asky[i]]=s[i]=='1';
}
std::vector<int>ans[3];
int main(){
	int orzyyb=gi();
	while(orzyyb--){
		int n=gi();
		for(int i=1;i<=n;++i)fa[i]=i,siz[i]=1;
		k=0;for(int i=1;i+1<=n;i+=2)askx[++k]=i,asky[k]=i+1;ask(0);
		k=0;for(int i=2;i+1<=n;i+=2)askx[++k]=i,asky[k]=i+1;ask(0);
		m=0;for(int i=1;i<=n;++i)if(!same[i-1])newx[++m]=i;
		for(int o=1;o<=3;o+=2){
			k=0;
			for(int i=o;i+2<=m;i+=4)askx[++k]=i,asky[k]=i+2;
			for(int i=o+1;i+2<=m;i+=4)askx[++k]=i,asky[k]=i+2;
			ask(1);
		}
		ans[0].clear();ans[1].clear();ans[2].clear();
		from[1]=p[newx[1]]=0,from[2]=p[newx[2]]=1;
		for(int i=3;i<=m;++i)
			if(lst[i])from[i]=p[newx[i]]=from[i-2];
			else from[i]=p[newx[i]]=3-from[i-1]-from[i-2];
		for(int i=1;i<=n;++i)L[i]=same[i-1]?L[i-1]:i;
		for(int i=1;i<=n;++i)ans[p[L[i]]].push_back(i);
		printf("A %d %d %d\n",ans[0].size(),ans[1].size(),ans[2].size());
		for(int i=0;i<3;++i){
			for(auto j:ans[i])printf("%d ",j);
			puts("");
		}
		fflush(stdout);
	}
	return 0;
}