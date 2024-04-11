#include <iostream>
#include <string>
using namespace std;

int csum[2000][2000];
int rsum[2000][2000];

string A[2000];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N,M;
	cin >> N >> M;
	int lowx = 2000;
	int highx = -1;
	int lowy = 2000;
	int highy = -1;
	int tot = 0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			rsum[i][j] = csum[i][j] = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		for(int j=0;j<M;j++)
		{
			if(A[i][j] != 'w') continue;
			lowx = min(lowx,i);
			highx = max(highx,i);
			lowy = min(lowy,j);
			highy = max(highy,j);
			rsum[i][j]++;
			csum[i][j]++;
			tot++;
		}
	}
	for(int i=0;i<N;i++)
		for(int j=1;j<M;j++)
			rsum[i][j] += rsum[i][j-1];
	for(int j=0;j<M;j++)
		for(int i=1;i<N;i++)
			csum[i][j] += csum[i-1][j];
	int d = max(highx-lowx,highy-lowy);
	int onB;
	for(int i=0;(i+d)<N;i++)
	{
		for(int j=0;(j+d)<M;j++)
		{
			if((i<lowx)&&(j<lowy)) continue;
			onB = rsum[i][j+d-1]-rsum[i][j];
			onB += rsum[i+d][j+d-1]-rsum[i+d][j];
			onB += csum[i+d-1][j]-csum[i][j];
			onB += csum[i+d-1][j+d]-csum[i][j+d];

			onB += (A[i][j]=='w')+(A[i][j+d]=='w')+(A[i+d][j]=='w')+(A[i+d][j+d]=='w');

			if(d==0) onB = (A[i][j]=='w');
			if(onB==tot)
			{
				for(int x=0;x<N;x++)
				{
					for(int y=0;y<M;y++)
					{
						if(A[x][y]=='w') cout << 'w';
						else if(((x==i)||(x==(i+d)))&&(y>=j)&&(y<=(j+d)))
							cout << '+';
						else if(((y==j)||(y==(j+d)))&&(x>=i)&&(x<=(i+d)))
							cout << '+';
						else cout << '.';
					}
					cout  << "\n";
				}
				return 0;
			}
		}
	}
	cout << -1 << "\n";
	return 0;
}