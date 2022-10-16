#include<iostream>
#include<vector>
#include<string>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include<random>
#define mp(x, y, z) pair<long long, long long> z=make_pair(x, y)
#define pb(x, y) x.push_back(y)
#define ff(x)  if(x>0)
#define cn(x) cin>>x
using namespace std;
typedef  vector<vector<vector<vector<vector<int>>>>> v5nt;
typedef  vector<vector<vector<vector<int>>>> v4nt;
typedef  vector<vector<vector<int>>> v3nt;
typedef long long ll;
typedef pair<int, int> pr;
typedef vector <long long>  vl;
typedef int nt;
#pragma comment(linker, "/STACK:2000000")
vector<vector<int>> matrix;
mt19937 mt(736);
int main()
{
	int n, m, ans=0;
	cin >> n >> m;
	matrix.resize(n);
	for (int i = 0; i<n; i++)
	{
		matrix[i].resize(m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char x;
			cin >> x;
			if (x == '.')
			{
				matrix[i][j] = 0;
			}
			else
			{
				matrix[i][j] = 1;
			}
		}
	}
	for (int i1 = 0; i1 < n; i1++)
	{
		for (nt i2 = i1 + 1; i2 < n; i2++)
		{
			for (int j1 = 0; j1 < m; j1++)
			{
				for (int j2 = j1 + 1; j2 < m; j2++)
				{
					nt cur = matrix[i1][j1] + matrix[i2][j2] + matrix[i1][j2] + matrix[i2][j1];
					if (cur == 3)
					{
						ans++;
					}
				}
			}
		}
	}
	if (ans == 0)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}