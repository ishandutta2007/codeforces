#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF 1<<30

using namespace std;

char A[105][105];
int n, m;

bool isBomb(char ch)
{
	if(ch == '*')
		return true;
	return false;
}
int X[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int Y[] = {0, -1, 1, 0, -1, 1, 0, -1, 1};
bool valid(int x, int y) {
	if(x < n && y < m && x >= 0 && y >= 0)
		return true;
	return false;
}
int count(int x, int y) {
	int c = 0;
	for (int i = 0; i < 9; ++i)
	{
		if(valid(x+X[i], y+Y[i])) {
			if(isBomb(A[x+X[i]][y+Y[i]]))
				c++;
		}
	}
	return c;
}
int value(int i, int j) {
	if(A[i][j] == '.')
		return 0;
	return ((int)(A[i][j] - '0'));
}
int main()
{
	fastio;
	#ifdef PIYUSH_AASHIRWAAD 
		I_O; 
	#endif	
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>A[i][j];
		}
	}
	bool b = false;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!isBomb(A[i][j]) && count(i, j) != value(i, j)) {
				b = true;
			}
		}
	}
	if(b)
		cout<<"NO";
	else
		cout<<"YES";
}