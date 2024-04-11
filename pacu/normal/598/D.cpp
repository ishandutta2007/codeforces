#include <cstdio>
#include <iostream>
using namespace std;

char A[1005][1005];
int N,M,K;
int comp[1005][1005];
int ans[1000000];
bool vis[1005][1005];
int C;

void dfs(int i,int j,int cc)
{
	comp[i][j] = cc;
	vis[i][j] = 1;
	if(i<N-1 && A[i+1][j]=='.' && !vis[i+1][j])
		dfs(i+1,j,cc);
	if(i<N-1 && A[i+1][j]=='*')
		ans[cc]++;
	if(j<M-1 && A[i][j+1]=='.' && !vis[i][j+1])
		dfs(i,j+1,cc);
	if(j<M-1 && A[i][j+1]=='*')
		ans[cc]++;
	if(i>0 && A[i-1][j]=='.' && !vis[i-1][j])
		dfs(i-1,j,cc);
	if(i>0 && A[i-1][j]=='*')
		ans[cc]++;
	if(j>0 && A[i][j-1]=='.' && !vis[i][j-1])
		dfs(i,j-1,cc);
	if(j>0 && A[i][j-1]=='*')
		ans[cc]++;
}

int main()
{
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0;i<N;i++)
		scanf("%s",A[i]);
	C=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(!vis[i][j] && A[i][j]=='.')
			{
				dfs(i,j,C);
				C++;
			}
	int a,b;
	for(int i=0;i<K;i++)
	{
		scanf("%d %d",&a,&b);
		a--,b--;
		printf("%d\n",ans[comp[a][b]]);
	}
}