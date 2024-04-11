// LUOGU_RID: 92415555
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e6+5;
int n,m,a[maxn],ord[maxn];
bool b[maxn];
int fa[maxn*4],s1[maxn*4];
ll s2[maxn*4];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
void merge(int x,int y){
	y=find(y);
	s2[y]+=1ll*a[(x+3)/4]*s1[x];
	s1[y]+=s1[x];
	fa[x]=y;
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n*m;i++){
		a[i]=read();
		ord[i]=i;
	}
	sort(ord+1,ord+n*m+1,[](int x,int y){
		return a[x]<a[y];
	});
	for(int i=1;i<=n*m*4;i++){
		fa[i]=i;
		s1[i]=1;
	}
	for(int i=1;i<=n*m;i++){
		int u=ord[i];
		for(int j=0;j<4;j++)
			b[u]^=(1ll*a[u]*s1[u*4-j]-s2[u*4-j])%2;
		if(b[u]){
			if((u-1)%m!=0) merge(u*4,(u-1)*4-1);
			if(u>m) merge(u*4-1,(u-m)*4-2);
			if(u%m!=0) merge(u*4-2,(u+1)*4-3);
			if(u<=m*(n-1)) merge(u*4-3,(u+m)*4);
		}
		else{
			if(u<=m*(n-1)) merge(u*4,(u+m)*4);
			if((u-1)%m!=0) merge(u*4-1,(u-1)*4-1);
			if(u>m) merge(u*4-2,(u-m)*4-2);
			if(u%m!=0) merge(u*4-3,(u+1)*4-3);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) printf("%d",b[m*(i-1)+j]);
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}