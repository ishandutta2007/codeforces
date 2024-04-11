#include<bits/stdc++.h>

using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("/home/piyush/Documents/input.txt", "r", stdin);
	freopen("/home/piyush/Documents/output.txt", "w", stdout);
	#endif/**/
	int n, m;
	cin>>n>>m;
	bool A[2001][2001]={{0}};
	string s;
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		for (int j = 0; j < m; ++j)
		{
			if(s[j] == '1')
				A[i][j] = true;
			else
				A[i][j] = false;
		}
	}
	int totalstatem[2001]={0};
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(A[i][j]) {
				totalstatem[j]++;
			}
		}
	}
	bool exists = false;
	for (int i = 0; i < n; ++i)
	{
		bool thisistheswitch = true;
		for (int j = 0; j < m; ++j)
		{
			if(A[i][j] && (totalstatem[j] == 1)) {
				thisistheswitch = false;
			}
		}
		if(thisistheswitch) {
			exists = true;
		}
	}
	if(exists) {
		cout<<"YES";
	}
	else {
		cout<<"NO";
	}
}