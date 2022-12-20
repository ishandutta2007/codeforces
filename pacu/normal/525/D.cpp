#include <cstdio>
using namespace std;

char A[2005][2005];
bool qin[2005][2005];
int R,C;

int qx[4000000];
int qy[4000000];

bool single(int x,int y)
{
	int cnt = 0;
	cnt += (A[x][y]=='*');
	cnt += (A[x+1][y]=='*');
	cnt += (A[x+1][y+1]=='*');
	cnt += (A[x][y+1]=='*');
	return (cnt==1);
}

bool bad(int x,int y)
{
	return single(x,y)||single(x-1,y)||single(x-1,y-1)||single(x,y-1);
}

int dx[] = {-1,0,1,-1,1,-1,0,1};
int dy[] = {-1,-1,-1,0,0,1,1,1};

int main()
{
	scanf("%d %d",&R,&C);
	for(int i=0;i<R;i++)
		scanf("%s",A[i+2]+2);
	for(int i=0;i<R+4;i++)
		for(int j=0;j<C+4;j++)
			if((i<2)||(j<2)||(i>=(R+2))||(j>=(C+2)))
				A[i][j] = '*';
	int len = 0;
	int cur = 0;
	for(int i=2;i<R+2;i++)
	{
		for(int j=2;j<C+2;j++)
		{
			if(bad(i,j))
			{
				qx[len] = i;
				qy[len] = j;
				qin[i][j] = 1;
				len++;
			}
		}
	}
	int a,b;
	while(cur < len)
	{
		a = qx[cur];
		b = qy[cur];
		A[a][b] = '.';
		for(int d=0;d<9;d++)
			if(A[a+dx[d]][b+dy[d]]=='*')
				if(!qin[a+dx[d]][b+dy[d]])
					if(bad(a+dx[d],b+dy[d]))
					{
						qx[len] = a+dx[d];
						qy[len] = b+dy[d];
						qin[a+dx[d]][b+dy[d]] = 1;
						len++;
					}
		cur++;
	}
	for(int i=2;i<R+2;i++)
	{
		for(int j=2;j<C+2;j++)
			printf("%c",A[i][j]);
		printf("\n");
	}
	return 0;
}