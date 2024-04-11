#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define SEG (1<<19)


int N;
int v[SEG];
int t[500000];
bool vis[500000];

int seg[2*SEG],l[2*SEG],r[2*SEG];

void init()
{
	for(int i=SEG;i<2*SEG;i++)
	{
		l[i] = r[i] = i-SEG;
		seg[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		l[i] = l[2*i], r[i] = r[2*i+1];
		if(v[seg[2*i]] >= v[seg[2*i+1]])
			seg[i] = seg[2*i];
		else
			seg[i] = seg[2*i+1];
	}
}

int low,high;

int getMax(int i)
{
	if((l[i]>high)||(r[i]<low)) return SEG-1;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	int a = getMax(2*i);
	int b = getMax(2*i+1);
	if(v[a]>=v[b]) return a;
	return b;
}

void update(int i)
{
	int ii = i;
	i += SEG;
	seg[i] = SEG-1;
	for(i/=2;i>0;i/=2)
	{
		if(v[seg[2*i]] >= v[seg[2*i+1]])
			seg[i] = seg[2*i];
		else
			seg[i] = seg[2*i+1];
	}
}


vector<int> lst;

void dfs(int i)
{
	//cout << "Enter " << i << '\n';
	vis[i] = 1;
	update(i);
	if(v[i] != N && !vis[v[i]])
		dfs(v[i]);
	if(t[i]>0)
	{
		while(1)
		{
			low = 0, high = t[i]-1;
			int j = getMax(1);
			if(v[j] > i)
				dfs(j);
			else
				break;
		}
	}
	lst.push_back(i);
	//cout << "Exit " << i << '\n';
}

int p[500000];

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&v[i]);
		if(v[i]==-1) v[i] = N;
		else v[i]--;
	}
	for(int i=0;i<N;i++)
		t[i] = N;
	for(int i=0;i<N;i++)
		if(v[i]!=N)
			t[v[i]] = i;
	init();
	for(int i=0;i<N;i++)
		if(!vis[i])
			dfs(i);
	for(int i=0;i<N;i++)
		p[lst[i]] = N-1-i;
	for(int i=0;i<N;i++)
		printf("%d ",p[i]+1);
	printf("\n");
}