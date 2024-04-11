// Author: Little09
// Problem: E. Balanced Binary Search Trees
// Contest: Codeforces Global Round 5
// URL: https://codeforces.com/contest/1237/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int cur=2,tp=1;
	while (cur<=n+1)
	{
		if (n==cur||n==cur-1)
		{
			cout << 1;
			return 0;
		}
		cur=cur*2+1;
		if (tp==0) cur--;
		tp^=1;
	}
	cout << 0;
	return 0;
}