#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x;
}
struct yyb{int a,b;}a[30001];
il bool operator <(const yyb&a,const yyb&b){return a.b<b.b;}
int f[30001],l[30001],r[30001],mx[30001],cnt[30001],ans[30001];
int main(){
	int n=gi(),m=gi();
	register int i,j,p;
	f[1]=f[2]=1;
	for(i=3;i<=n;++i){
		f[i]=f[i-1]+f[i-2];
		if(f[i]>=m)f[i]-=m;
	}
	for(i=1;i<=n;++i)a[i]=(yyb){i,gi()};
	std::sort(a+1,a+n+1);
	int q=gi();
	for(i=1;i<=q;++i)l[i]=gi(),r[i]=gi();
	for(i=1;i<=n;++i){
		p=a[i].b%m;
		for(j=1;j<=q;++j){
			if(a[i].a<l[j]||r[j]<a[i].a)continue;
			if(mx[j]==a[i].b)continue;
			mx[j]=a[i].b,ans[j]+=f[++cnt[j]]*p%m;
		}
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]%m);
	return 0;
}