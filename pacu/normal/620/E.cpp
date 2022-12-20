#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N,M;
vector<int> edges[400000];
int order[400000];
int color[400000];
int o1[400000],o2[400000];
int C;

void dfs(int i,int par)
{
	order[C] = i;
	o1[i] = C++;
	for(int j=0;j<edges[i].size();j++)
		if(edges[i][j]!=par)
			dfs(edges[i][j],i);
	o2[i] = C-1;
}

#define SEG (1<<20)
long long seg[2*SEG],up[2*SEG];
int l[2*SEG],r[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		if(i-SEG < C) seg[i] = (1LL<<color[order[i-SEG]]);
		else seg[i] = 0;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		seg[i] = seg[2*i]|seg[2*i+1];
		l[i] = l[2*i], r[i] = r[2*i+1];
	}
}

void push(int i)
{
	if(up[i])
	{
		seg[i] = up[i];
		if(i<SEG)
			up[2*i] = up[2*i+1] = up[i];
		up[i] = 0;
	}
}

int low,high;
void update(int i,int col)
{
	if((l[i]>high)||(r[i]<low))
	{
		push(i);
		return;
	}
	if((l[i]>=low)&&(r[i]<=high))
	{
		up[i] = (1LL<<col);
		push(i);
		return;
	}
	push(i);
	update(2*i,col);
	update(2*i+1,col);
	seg[i] = seg[2*i]|seg[2*i+1];
}

long long getSeg(int i)
{
	push(i);
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	return getSeg(2*i)|getSeg(2*i+1);
}

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&color[i]);
		color[i]--;
	}
	int a,b;
	for(int i=0;i<N-1;i++)
	{
		scanf("%d %d",&a,&b);
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0,-1);
	init();
	int tp,v,c;
	for(int i=0;i<M;i++)
	{
		scanf("%d",&tp);
		if(tp == 1)
		{
			scanf("%d %d",&v,&c);
			v--,c--;
			low = o1[v], high = o2[v];
			update(1,c);
		}
		else
		{
			scanf("%d",&v);
			v--;
			low = o1[v], high = o2[v];
			printf("%d\n",__builtin_popcountll(getSeg(1)));
		}
	}
}