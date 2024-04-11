#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;

int n,m;
int de[M],fa[M][20],size[M];
int head[M*2],cnt;
struct node
{
	int to,next;
}b[M*2];
void add(int u,int to)
{
	b[++cnt].to=to,b[cnt].next=head[u],head[u]=cnt;
}

void dfs(int u,int f)
{
	de[u]=de[f]+1,size[u]=1,fa[u][0]=f;
	for (int i=1;i<=19;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for (int i=head[u];i;i=b[i].next)
		if (b[i].to!=f)
			dfs(b[i].to,u),size[u]+=size[b[i].to];
}

int LCA(int x,int y)
{
	if (de[y]>de[x])
		swap(x,y);
	for (int i=19;i>=0;i--)
		if (de[fa[x][i]]>=de[y])
			x=fa[x][i];
	if (x==y)
		return x;
	for (int i=19;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int jump(int x,int len)//xlen
{
	int r=x;
	for (int i=19;i>=0;i--)
		if (de[x]-de[fa[r][i]]<=len)
			r=fa[r][i];
	return r;
}

int main()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(1,0);
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if (x==y)
		{
			cout<<size[1]<<endl;
			continue;
		}
		int k=LCA(x,y);
		int len=de[x]-de[k]+de[y]-de[k];
		if (len%2==1)
		{
			cout<<0<<endl;
			continue;
		}
		if (de[y]==de[x])//LCA
		{
			x=jump(x,len/2-1),y=jump(y,len/2-1);
			cout<<size[1]-size[x]-size[y]<<endl;
			continue;
		}
		//LCA
		if (de[x]<de[y])
			swap(x,y);
		int zd=jump(x,len/2),zdl=jump(x,len/2-1);
		cout<<size[zd]-size[zdl]<<endl;
	}
	return 0;
}