#include <cstdio>
#include <iostream>
#include <iostream>
#include <cmath>
using namespace std;

char A[1001][1001];
int N;

int dx[] = {-1,0,1,0,-1,-1,1,1};
int dy[] = {0,1,0,-1,-1,1,1,-1};

int nextZero[1000][1000][8];
int num2[1000][1000][8];
int num3[1000][1000][8];

bool inb(int i,int j,int d,int mult)
{
	return (i+mult*dx[d] >= 0 && i+mult*dx[d] < N && j+mult*dy[d] >= 0 && j+mult*dy[d] < N);
}

void dfs(int i,int j,int d)
{
	if(nextZero[i][j][d]!=-1) return;
	bool inbounds = inb(i,j,d,1);
	if(inbounds)
		dfs(i+dx[d],j+dy[d],d);
	if(A[i][j]=='0') nextZero[i][j][d] = 0;
	else if(inbounds) nextZero[i][j][d] = 1 + nextZero[i+dx[d]][j+dy[d]][d];
	else nextZero[i][j][d] = 1;
	
	if(inbounds) num2[i][j][d] = (A[i][j]=='2') + num2[i+dx[d]][j+dy[d]][d];
	else num2[i][j][d] = (A[i][j]=='2');
	
	if(inbounds) num3[i][j][d] = (A[i][j]=='3') + num3[i+dx[d]][j+dy[d]][d];
	else num3[i][j][d] = (A[i][j]=='3');
}

bool isleq(pair<int,int> a,pair<int,int> b)
{
	if(a.first <= b.first && a.second <= b.second) return 1;
	if(a.first > b.first && a.second > b.second) return 0;
	int x = a.first - b.first;
	int y = b.second - a.second;
	return x <= y*log2(3);
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%s",A[i]);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int d=0;d<8;d++)
				nextZero[i][j][d] = num2[i][j][d] = num3[i][j][d] = -1;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int d=0;d<8;d++)
				dfs(i,j,d);
	pair<int,int> ans = make_pair(-1,-1);
	pair<int,int> cur;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++) for(int k=0;k<8;k+=4)
		{
			int len = N;
			for(int d=k;d<k+4;d++)
				len = min(len,nextZero[i][j][d]);
			if(len==0) continue;
			cur = make_pair(0,0);
			for(int d=k;d<k+4;d++)
			{
				cur.first += num2[i][j][d];
				cur.second += num3[i][j][d];
				if(inb(i,j,d,len))
				{
					cur.first -= num2[i+len*dx[d]][j+len*dy[d]][d];
					cur.second -= num3[i+len*dx[d]][j+len*dy[d]][d];
				}
			}
			if(A[i][j]=='2') cur.first -= 3;
			else if(A[i][j]=='3') cur.second -= 3;
//			cout << i << ' ' << j << ": " << len << ": " << cur.first << " - " << cur.second << '\n';
			if(!isleq(cur,ans))
				ans = cur;
		}
	if(ans.first==-1) printf("0\n");
	else
	{
		int best = 1;
		for(int i=0;i<ans.first;i++)
			best = (2LL*best)%1000000007;
		for(int i=0;i<ans.second;i++)
			best = (3LL*best)%1000000007;
		printf("%d\n",best);
	}
}