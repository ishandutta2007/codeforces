#include<bits/stdc++.h>
using namespace std;

int n,x,y,hd[100010],cnt,d[100010];
struct node{int to,next;}e[200010];

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<n; i++) scanf("%d%d",&x,&y),addedge(x,y),d[x]++,d[y]++;
	for (int i=1; i<=n; i++) if (d[i]==2) return puts("NO"),0;
	puts("YES");
	return 0;
}