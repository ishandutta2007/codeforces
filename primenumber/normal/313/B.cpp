#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>

#define rep(i,n)	for(int i = 0;i < n;i++)
#define rep2(i,n)	for(int i = 1;i <= n;i++)
#define each(i,x)	for(auto & i : x)

using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = str.size();
	vector<int> ary(n,0);
	rep(i,n-1)
	{
		ary[i+1] = ary[i];
		if(str[i+1] == str[i])
		{
			ary[i+1]++;
		}
	}
	int m;
	cin >> m;
	rep(i,m)
	{
		int l,r;
		cin >> l >> r;
		l--;r--;
		cout << (ary[r]-ary[l]) << endl;
	}
	return 0;
}