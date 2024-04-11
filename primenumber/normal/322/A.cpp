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
	int m,n;
	cin >> n >> m;
	cout << (n+m-1) << endl;
	rep2(i,m)
	{
		cout << 1 << ' ' << i << endl;
	}
	rep2(i,n-1)
	{
		cout << (i+1) << ' ' << 1 << endl;
	}
	return 0;
}