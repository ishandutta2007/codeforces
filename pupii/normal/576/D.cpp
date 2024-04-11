#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m;
struct matrix{
	std::bitset<151>f[151];
}now,T;
matrix operator*(matrix a,matrix b){
	matrix c;
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j){
			bool t=b.f[i][j];
			b.f[i][j]=b.f[j][i];
			b.f[j][i]=t;
		}
	for(int i=1;i<=n;++i)if(a.f[i].any())
		for(int j=1;j<=n;++j)
			c.f[i][j]=(a.f[i]&b.f[j]).any();
	return c;
}
matrix operator^(matrix a,int b){
	matrix c;for(int i=1;i<=n;++i)c.f[i][i]=1;
	while(b){
		if(b&1)c=c*a;
		a=a*a;b>>=1;
	}
	return c;
}
struct edge{int a,b,c;}s[151];
std::bitset<151>Yn;
std::vector<int>G[151];
void dfs(int x){
	Yn[x]=1;
	for(int i:G[x])if(!Yn[i])dfs(i);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi();
	for(int i=1;i<=m;++i)s[i].a=gi(),s[i].b=gi(),s[i].c=gi();
	std::sort(s+1,s+m+1,[](edge a,edge b){return a.c<b.c;});
	now.f[1][1]=1;now=now*(T^s[1].c);
	s[m+1].c=2e9;
	Yn[n]=1;
	for(int i=1;i<=m;++i){
		T.f[s[i].a][s[i].b]=1;
		G[s[i].b].push_back(s[i].a);
		if(Yn[s[i].b]&&!Yn[s[i].a])dfs(s[i].a);
		if((Yn&now.f[1]).any()){
			int t=s[i].c;
			while(!now.f[1][n])++t,now=now*T;
			printf("%d\n",t);
			return 0;
		}else now=now*(T^s[i+1].c-s[i].c);
	}
	puts("Impossible");
	return 0;
}