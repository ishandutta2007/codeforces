#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 100005
int n,m,cnt;
int a[MN],b[MN],c[2*MN],d[MN];
int h[MN],iter[MN],nxt[MN*2],to[MN*2],v[MN*2],tot=1;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int stk[MN],tp;
void dfs(int u){
	for(int&i=iter[u];i;i=nxt[i])if(!v[i]){
		v[i]=v[i^1]=1;
		dfs(to[i]);
	}
	stk[++tp]=u;
}
int main(){
	scanf("%d",&n);
	F(i,1,n-1)scanf("%d",a+i),c[i]=a[i];
	F(i,1,n-1)scanf("%d",b+i),c[n+i-1]=b[i];
	F(i,1,n-1)if(a[i]>b[i])return puts("-1"),0;
	std::sort(c+1,c+n+n-1),m=unique(c+1,c+n+n-1)-c-1;
	F(i,1,n-1)a[i]=std::lower_bound(c+1,c+m+1,a[i])-c;
	F(i,1,n-1)b[i]=std::lower_bound(c+1,c+m+1,b[i])-c;
	F(i,1,n-1)d[a[i]]^=1;
	F(i,1,n-1)d[b[i]]^=1;
	F(i,1,m)if(d[i])++cnt;
	if(cnt!=0&&cnt!=2)return puts("-1"),0;
	int s=1;
	F(i,2,m)if(d[i])s=i;
	F(i,1,n-1)ins(a[i],b[i]),ins(b[i],a[i]);
	F(i,1,m)iter[i]=h[i];
	dfs(s);
	if(tp!=n)return puts("-1"),0;
	F(i,1,tp)printf("%d%c",c[stk[i]]," \n"[i==tp]);
	return 0;
}