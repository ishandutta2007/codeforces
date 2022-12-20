#include <cstdio>
#include <algorithm>
using namespace std;

int N,M;
int A[1000][1000];
int Q;
int sq[1000][1000];
int mx[1000][1000][11][11];

int rmax(int a,int b,int c,int d)
{
	int x = 0;
	while(a+(1<<(x+1)) <= c) x++;
	int y = 0;
	while(b+(1<<(y+1)) <= d) y++;
	return max(max(mx[a][b][x][y],mx[c+1-(1<<x)][b][x][y]),max(mx[a][d+1-(1<<y)][x][y],mx[c+1-(1<<x)][d+1-(1<<y)][x][y]));
}

int binSearch(int low,int high,int a,int b,int c,int d)
{
	if(low==high) return low;
	if(low+1==high)
	{
		if(rmax(a,b,c+1-high,d+1-high)>=high) return high;
		return low;
	}
	int mid =  (low+high)/2;
	if(rmax(a,b,c+1-mid,d+1-mid)>=mid) return binSearch(mid,high,a,b,c,d);
	else return binSearch(low,mid-1,a,b,c,d);
}

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d",&A[i][j]);
	for(int i=N-1;i>=0;i--)
		for(int j=M-1;j>=0;j--) if(A[i][j])
		{
			if(i==N-1 || j==M-1) sq[i][j] = 1;
			else sq[i][j] = 1 + min(min(sq[i][j+1],sq[i+1][j]),sq[i+1][j+1]);
		}
	for(int x=0;x<=10;x++)
		for(int y=0;y<=10;y++)
			for(int i=0;i<=N-(1<<x);i++)
				for(int j=0;j<=M-(1<<y);j++)
				{
					if(x==0 && y==0) mx[i][j][x][y] = sq[i][j];
					else if(x==0) mx[i][j][x][y] = max(mx[i][j][x][y-1],mx[i][j+(1<<(y-1))][x][y-1]);
					else mx[i][j][x][y] = max(mx[i][j][x-1][y],mx[i+(1<<(x-1))][j][x-1][y]);
				}
	scanf("%d",&Q);
	int a,b,c,d;
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		a--,b--,c--,d--;
		printf("%d\n",binSearch(0,min(c+1-a,d+1-b),a,b,c,d));
	}
}