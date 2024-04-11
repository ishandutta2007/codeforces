#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5+1;

int n,m,head[N],cnt,to[N],ans[N],tmp;
struct nd{int ne,to;}e[N*2];
void in(int x,int y){e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;}
priority_queue<int>q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),in(y,x),to[x]++;
	for(int i=1;i<=n;++i)if(!to[i])q.push(i);
	tmp=n+1;
	while(!q.empty())
	{
		int x=q.top();q.pop();
		ans[x]=--tmp;
		for(int i=head[x];i;i=e[i].ne)
		{
			to[e[i].to]--;
			if(to[e[i].to]==0)q.push(e[i].to);
		}
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
}