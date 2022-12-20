#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
using namespace std;

int cnts[100][100];

int main()
{
	int N;
	int t,c;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<100;j++) cnts[i][j] = 0;
		cin >> t;
		for(int j=0;j<t;j++)
		{
			cin >> c;
			c--;
			cnts[i][c]++;
		}
	}
	for(int i=0;i<N;i++)
	{
		bool good = 1;
		for(int j=0;j<N;j++)
		{
			if(j==i) continue;
			bool bad = 1;
			for(int k=0;k<100;k++)
				if(cnts[j][k]>cnts[i][k]) bad = 0;
			if(bad) good = 0;
		}
		if(good) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}