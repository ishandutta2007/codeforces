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
	long long x,y,k;
	cin >> x >> y >> k;
	long long c = 0;
	if(x <= 0 && y <= 0)
	{
		if(x >= k || y >= k)
			cout << 0 << endl;
		else
			cout << -1 << endl;
	}
	else
	{
		rep(i,1000)
		{
			if(y > x)
			{
				swap(x,y);
			}
			if(x >= k)
				break;
			if(y < 0)
			{
				c += (abs(y)/x+1);
				y += x * (abs(y)/x+1);
			}
			else
			{
				y += x;
				c++;
			}
		}
		cout << c << endl;
	}
	return 0;
}