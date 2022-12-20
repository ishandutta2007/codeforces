#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> edges[500000];

bool vis[500000];
int order[1000000];
int first[500000],second[500000];
int C;

void dfs(int i)
{
	vis[i] = 1;
	first[i] = C;
	order[C++] = i;
	for(int j=0;j<edges[i].size();j++)
		if(!vis[edges[i][j]])
			dfs(edges[i][j]);
	second[i] = C;
	order[C++] = i;
}

#define SEG (1<<20)

int segFill[2*SEG],up[2*SEG];
int segEmpty[2*SEG];
int l[2*SEG],r[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		segFill[i] = -1;
		up[i] = 0;
		segEmpty[i] = 0;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		segFill[i] = -1;
		up[i] = 0;
		segEmpty[i] = 0;
		l[i] = l[2*i];
		r[i] = r[2*i+1];
	}
}

void push(int i)
{
	if(up[i]>0)
	{
		if(i<SEG)
		{
			up[(i<<1)] = up[i];
			up[(i<<1)+1] = up[i];
		}
		segFill[i] = up[i];
		up[i] = 0;
	}
}

int getFill(int i,int loc)
{
	push(i);
	if(i>=SEG) return segFill[i];
	else if(r[(i<<1)] >= loc) return getFill((i<<1),loc);
	else return getFill((i<<1)+1,loc);
}

int low,high;

void setFill(int i,int v)
{
	push(i);
	if((l[i]>high)||(r[i]<low)) return;
	if((l[i]>=low)&&(r[i]<=high))
	{
		up[i] = v;
		push(i);
		return;
	}
	setFill((i<<1),v);
	setFill((i<<1)+1,v);
	segFill[i] = max(segFill[(i<<1)],segFill[(i<<1)+1]);
}

void setEmpty(int loc,int v)
{
	loc += SEG;
	segEmpty[loc] = v;
	for(loc/=2;loc>0;loc/=2)
		segEmpty[loc] = max(segEmpty[2*loc],segEmpty[2*loc+1]);
}

int getEmpty(int i)
{
	if((l[i]>high)||(r[i]<low)) return 0;
	if((l[i]>=low)&&(r[i]<=high)) return segEmpty[i];
	return max(getEmpty((i<<1)),getEmpty((i<<1)+1));
}

int main()
{
	int N,a,b;
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		scanf("%d %d",&a,&b);
		a--,b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	C = 0;
	dfs(0);
	init();
	int Q,tp,v;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d",&tp,&v);
		v--;
		if(tp==1)
		{
			low = first[v];
			high = second[v];
			setFill(1,i+1);
		}
		if(tp==2)
			setEmpty(first[v],i+1);
		if(tp==3)
		{
			low = first[v];
			high = second[v];
			a = getFill(1,first[v]);
			b = getEmpty(1);
			printf("%d\n",a>=b);
		}
	}
}