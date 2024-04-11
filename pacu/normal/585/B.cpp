#include <iostream>
#include <string>
using namespace std;

string A[3];
bool vis[105][3];

int N;

bool dfs(int r,int c)
{
	vis[r][c] = 1;
	if(r>=N-1) return 1;
	bool ans = 0;
	if(A[c][r+1] == '.')
	{
		if(A[c][r+2] == '.' && A[c][r+3] == '.')
			if(!vis[r+3][c])
				ans |= dfs(r+3,c);
		if(c>0 && A[c-1][r+1] == '.' && A[c-1][r+2] == '.' && A[c-1][r+3] == '.')
			if(!vis[r+3][c-1])
				ans |= dfs(r+3,c-1);
		if(c<2 && A[c+1][r+1] == '.' && A[c+1][r+2] == '.' && A[c+1][r+3] == '.')
			if(!vis[r+3][c+1])
				ans |= dfs(r+3,c+1);
	}
	return ans;
}

void test()
{
	for(int c=0;c<3;c++)
		for(int r=N;r<N+5;r++)
			A[c] += '.';
	for(int c=0;c<3;c++)
		for(int r=0;r<N+5;r++)
			vis[r][c] = 0;
	int c = 0;
	if(A[1][0] == 's') c = 1;
	if(A[2][0] == 's') c = 2;
	if(dfs(0,c)) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		int K;
		cin >> N >> K;
		for(int j=0;j<3;j++)
			cin >> A[j];
		test();
	}
}