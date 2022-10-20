#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
int n,m,k,fo[N],bk[N],p[N],d,ansa=0,ansb=0;
bool book[N];
vector<int> vt[N],bt[N];
priority_queue<pair<int,int> > pq;
int main(){
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		bt[y].push_back(x);
		vt[x].push_back(y);
	}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&p[i]);
		p[i]--;
	}
	memset(bk,63,sizeof(bk));
	memset(book,false,sizeof(book));
	bk[p[k-1]]=0;
	pq.push(make_pair(0,p[k-1]));
	while(!pq.empty())
	{
		x=pq.top().S;
		pq.pop();
		if(book[x])
		{
			continue;
		}
		book[x]=true;
		for(i=0;i<bt[x].size();i++)
		{
			y=bt[x][i];
			if(bk[y]>bk[x]+1)
			{
				bk[y]=bk[x]+1;
				pq.push(make_pair(-bk[y],y));
			}
		}
	}
	for(i=0;i+1<k;i++)
	{
		if(bk[p[i]]!=bk[p[i+1]]+1)
		{
			ansa++;
		}
	}
	for(i=0;i+1<k;i++)
	{
		for(x=0;x<vt[p[i]].size();x++)
		{
			y=vt[p[i]][x];
			if(bk[p[i]]==bk[y]+1&&y!=p[i+1])
			{
				ansb++;
				break;
			}
		}
	}
	printf("%d %d\n",ansa,ansb);
	return 0;
}