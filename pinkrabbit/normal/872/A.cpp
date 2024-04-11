#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
inline int Min(int p,int q){return p<q?p:q;}
inline int Max(int p,int q){return p>q?p:q;}
int n,m,a[10],b[10],A=100,B=100;
void init(){
	int x;
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%d",&x), a[x]=1, A=Min(A,x);
	F(i,1,m) scanf("%d",&x), b[x]=1, B=Min(B,x);
}
int main(){
	init();
	F(i,1,9) if(a[i]&&b[i]) {printf("%d",i); return 0;}
	if(A>B) printf("%d%d",B,A);
	else printf("%d%d",A,B);
	return 0;
}