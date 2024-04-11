#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;
int n;
vector < int > v;
int main()
{
     cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	int s = 0;
	for (int i = 0; i < v.size() - 1; i++) s += v[i];
	cout << v[v.size()-1] - s+1;

	return 0;
}