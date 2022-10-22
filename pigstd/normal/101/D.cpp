#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int n,size[M],t[M];
double f[M];

struct node
{
	int id,w;
}p[M];

struct edge{int to,next,w;}e[M<<1];int cnt,head[M];
void add(int u,int to,int w){e[++cnt].to=to,e[cnt].w=w,e[cnt].next=head[u],head[u]=cnt;}

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

bool cmp(node a,node b)
{
	return (a.w*2+t[a.id])*1.0/size[a.id]<1.0*(b.w*2+t[b.id])/size[b.id];
}

void dfs(int k,int fa)
{
	size[k]=1;int tot=0,wait=0;
	for (int i=head[k];i;i=e[i].next)
		if (e[i].to!=fa)
			dfs(e[i].to,k),t[k]+=2*e[i].w+t[e[i].to],size[k]+=size[e[i].to];
	for (int i=head[k];i;i=e[i].next)
		if (e[i].to!=fa)
			p[++tot].id=e[i].to,p[tot].w=e[i].w;
	sort(p+1,p+1+tot,cmp);int son=(k==1?n-1:size[k]);
	for (int i=1;i<=tot;i++)
	{
		f[k]+=(wait+p[i].w+f[p[i].id])*1.0*size[p[i].id]/son;
		wait+=t[p[i].id]+2*p[i].w;
	}
}

int main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int a=read(),b=read(),c=read();
		add(a,b,c),add(b,a,c);
	}
	dfs(1,0);
	printf("%.12lf",f[1]);
	return 0;
}