#include <cstdio>
using namespace std;

int N,M;
int open[1500][1500];
bool vis[1500][1500];
int lastx[1500][1500];
int lasty[1500][1500];
int x,y;

int mod(int i,int k)
{
	i %= k;
	while(i<0)
		i+=k;
	return i;
}

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

bool dfs(int i,int j)
{
	int ki = mod(i,N);
	int kj = mod(j,M);
	if(!open[ki][kj])
		return 0;
	if(vis[ki][kj])
	{
		if((lastx[ki][kj]!=i)||(lasty[ki][kj]!=j))
			return 1;
		else
			return 0;
	}
	vis[ki][kj] = 1;
	lastx[ki][kj] = i;
	lasty[ki][kj] = j;
	for(int d=0;d<4;d++)
	{
		if(dfs(i+dx[d],j+dy[d]))
			return 1;
	}
	return 0;
}



int main()
{
	char s[2500];
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%s",s);
		for(int j=0;j<M;j++)
		{
			vis[i][j] = 0;
			open[i][j] = (s[j]!='#');
			if(s[j]=='S')
			{
				x = i;
				y = j;
			}
		}
	}
	if(dfs(x,y))
		printf("Yes\n");
	else
		printf("No\n");
}