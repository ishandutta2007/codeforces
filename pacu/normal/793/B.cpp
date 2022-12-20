#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int N,M;
string A[1000];
bool getS[1000][1000];
bool getT[1000][1000];
int sx,sy,tx,ty;

void getAccess(int x,int y,bool out[1000][1000])
{
	for(int i=x;i<N && A[i][y]=='.';i++)
		out[i][y] = 1;
	for(int i=x;i>=0 && A[i][y]=='.';i--)
		out[i][y] = 1;
	for(int j=y;j<M && A[x][j]=='.';j++)
		out[x][j] = 1;
	for(int j=y;j>=0 && A[x][j]=='.';j--)
		out[x][j] = 1;
}

int main()
{
//	cin.tie(0);
//	ios::sync_with_stdio(0);
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		for(int j=0;j<M;j++)
		{
			if(A[i][j]=='S')
			{
				sx = i, sy = j;
				A[i][j] = '.';
			}
			if(A[i][j]=='T')
			{
				tx = i, ty = j;
				A[i][j] = '.';
			}
		}
	}
	getAccess(sx,sy,getS);
	getAccess(tx,ty,getT);
	for(int i=0;i<N;i++)
	{
		bool foundS = 0;
		bool foundT = 0;
		for(int j=0;j<M;j++)
		{
			if(A[i][j]=='*') foundS = foundT = 0;
			if(getS[i][j]) foundS = 1;
			if(getT[i][j]) foundT = 1;
			if(foundS && foundT)
			{
				cout << "YES\n";
				return 0;
			}
		}
	}
	for(int j=0;j<M;j++)
	{
		bool foundS = 0;
		bool foundT = 0;
		for(int i=0;i<N;i++)
		{
			if(A[i][j]=='*') foundS = foundT = 0;
			if(getS[i][j]) foundS = 1;
			if(getT[i][j]) foundT = 1;
			if(foundS && foundT)
			{
				cout << "YES\n";
				return 0;
			}			
		}
	}
	cout << "NO\n";
	return 0;
}