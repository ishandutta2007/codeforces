#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int out[M],n;
double ans; 

struct edge
{
	int to,next;
}e[M*2];int head[M],cnt;
void adde(int u,int to)
{
	e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;
}

void dfs(int u,int fa,int l,double j)
{
	if (out[u]==1&&fa!=0)
		{ans+=j*l;return;}
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa)
		{
			if (fa==0)
				dfs(e[i].to,u,l+1,j/out[u]);
			else
				dfs(e[i].to,u,l+1,j/(out[u]-1));
		}
}

int main()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		adde(x,y),adde(y,x);out[x]++,out[y]++;
	}
	dfs(1,0,0,1);
	printf("%.10lf",ans);
	return 0;
}