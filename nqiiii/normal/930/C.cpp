#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100000;
int n,m,s[maxn+10],f[maxn+10],g[maxn+10],c[maxn+10],ans;
struct node{
	int id,v;
	bool operator<(const node &t)const{
		return v==t.v?id<t.id:v<t.v;
	}
}a[maxn+10];
void work(int *f){
	for(int i=1;i<=m;++i){
		a[i].id=i; a[i].v=s[i]; c[i]=0;
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;++i){
		for(int j=a[i].id;j;j-=j&-j) f[a[i].id]=max(f[a[i].id],c[j]);
		++f[a[i].id];
		for(int j=a[i].id;j<=m;j+=j&-j) c[j]=max(c[j],f[a[i].id]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int l,r; scanf("%d%d",&l,&r);
		++s[l]; --s[r+1];
	}
	for(int i=1;i<=m;++i) s[i]+=s[i-1];
	work(f); reverse(s+1,s+m+1); work(g);
	for(int i=1;i<=m;++i) ans=max(ans,f[i]+g[m+1-i]-1);
	printf("%d",ans);
}