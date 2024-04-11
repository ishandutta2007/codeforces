#include <iostream>
#include <cstdio>
using namespace std;

long long A[2000][2000];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&A[i][j]);
	long long major[4000];
	for(int i=0;i<N;i++)
	{
		int x = 0;
		int y = i;
		major[i] = 0;
		while(y>=0)
		{
			major[i] += A[x][y];
			x++;
			y--;
		}
	}
	for(int i=1;i<N;i++)
	{
		int x = i;
		int y = N-1;
		major[i+(N-1)] = 0;
		while(x<N)
		{
			major[i+(N-1)] += A[x][y];
			x++;
			y--;
		}
	}
	long long minor[4000];
	for(int i=(N-1);i>=0;i--)
	{
		int x = 0;
		int y = i;
		minor[(N-1)-i] = 0;
		while(y<N)
		{
			minor[(N-1)-i] += A[x][y];
			x++;
			y++;
		}
	}
	for(int i=1;i<N;i++)
	{
		int x = i;
		int y = 0;
		minor[(N-1)+i] = 0;
		while(x<N)
		{
			minor[(N-1)+i] += A[x][y];
			x++;
			y++;
		}
	}
	long long bestA = 0;
	int xbestA = -1;
	int ybestA = -1;
	long long bestB = 0;
	int xbestB = -1;
	int ybestB = -1;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			long long cur = major[i+j]+minor[(i-j)+(N-1)]-A[i][j];
			if(!((i+j)%2))
			{
				if(cur>=bestA)
				{
					bestA = cur;
					xbestA = i;
					ybestA = j;
				}
			}
			else
			{
				if(cur>=bestB)
				{
					bestB = cur;
					xbestB = i;
					ybestB = j;
				}
			}
		}
	cout << bestA+bestB << endl;
	cout << xbestA+1 << " " << ybestA+1 << " " << xbestB+1 << " " << ybestB+1 << endl;
}