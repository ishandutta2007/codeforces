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
	int a,b;
	cin >> a >> b;
	string s;
	cin >> s;
	int n = s.size();
	vector<pair<int,int>> ary(n+1,make_pair(0,0));
	int x = 0;
	int y = 0;
	rep(i,n)
	{
		switch(s[i])
		{
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;
			case 'R':
				x++;
				break;
			case 'L':
				x--;
				break;
		}
		ary[i+1] = make_pair(x,y);
	}
	int mx = ary[n].first;
	int my = ary[n].second;
	if(mx < 0)
	{
		mx = -mx;
		a = -a;
		rep(i,n+1)
		{
			ary[i].first = -ary[i].first;
		}
	}
	if(my < 0)
	{
		my = -my;
		b = -b;
		rep(i,n+1)
		{
			ary[i].second = -ary[i].second;
		}
	}
	if(mx == 0)
	{
		if(my == 0)
		{
			bool flg = false;
			rep(i,n+1)
			{
				if(ary[i].first == a && ary[i].second == b)
				{
					flg = true;
					break;
				}
			}
			if(flg)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		else
		{
			bool flg = false;
			rep(i,n+1)
			{
				if(ary[i].first == a && ary[i].second <= b && (b - ary[i].second) % my == 0)
				{
					flg = true;
					break;
				}
			}
			if(flg)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}
	else if(my == 0)
	{
		bool flg = false;
		rep(i,n+1)
		{
			if(ary[i].first <= a && ary[i].second == b && (a - ary[i].first) % mx == 0)
			{
				flg = true;
				break;
			}
		}
		if(flg)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	else
	{
		bool flg = false;
		rep(i,n+1)
		{
			if(ary[i].first <= a && ary[i].second <= b && (a - ary[i].first) % mx == 0 && (b - ary[i].second) % my == 0 && (a - ary[i].first) / mx == (b - ary[i].second) / my)
			{
				flg = true;
				break;
			}
		}
		if(flg)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}