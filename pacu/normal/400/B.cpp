#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
char A[1000][1000];
int main()
{
	int n,m;
	string s;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> s;
		for(int j=0;j<m;j++)
			A[i][j] = s[j];
	}
	bool bad = 0;
	vector<int> dif;
	for(int i=0;i<n;i++)
	{
		int dwarf,candy;
		for(int j=0;j<m;j++)
		{
			if(A[i][j]=='G')
				dwarf = j;
			if(A[i][j]=='S')
				candy = j;
		}
		if(dwarf > candy)
			bad = 1;
		dif.push_back(candy-dwarf);
	}
	if(bad)
	{
		cout << -1 << endl;
		return 0;
	}
	sort(dif.begin(),dif.end());
	int c = 1;
	for(int i=1;i<n;i++)
		if(dif[i] != dif[i-1])
			c++;
	cout << c << endl;
	return 0;
}