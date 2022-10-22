#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>

#define rep(i,n)	for(int i = 0;i < n;i++)

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> ary(n);
	vector<int> ary2(n);
	rep(i,n)
	{
		cin >> ary[i] >> ary2[i];
	}
	int k = n;
	rep(i,n)
	{
		rep(j,n)
		{
			if(i == j)
				continue;
			if(ary[i] == ary2[j])
			{
				k--;
				break;
			}
		}
	}
	cout << k << endl;
	return 0;
}