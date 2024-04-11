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

vector<int> search(vector<vector<char>> & ary,int n,int i = 0)
{
	rep(j,n)
	{
		if(ary[i][j] == '.')
		{
			if(i < n-1)
			{
				auto res = search(ary,n,i+1);
				if(!res.empty())
				{
					res.push_back(j);
					return res;
				}
				else
				{
					vector<int> res;
					return res;
				}
			}
			else
			{
				vector<int> res;
				res.push_back(j);
				return res;
			}
		}
	}
	vector<int> res;
	return res;
}

int main()
{
	int n;
	scanf("%d ",&n);
	vector<vector<char>> ary(n,vector<char>(n,0));
	vector<vector<char>> ary2(n,vector<char>(n,0));
	rep(i,n)
	{
		rep(j,n)
		{
			cin>>ary[i][j];
			ary2[j][i] = ary[i][j];
		}
	}
	auto res = search(ary,n,0);
	auto res2 = search(ary2,n,0);
	if(res.empty())
	{
		if(res2.empty())
		{
			cout << -1<<endl;
		}
		else
		{
			rep(i,n)
			{
				cout<<res2[i]+1<<' '<<n-i<<endl;
			}
		}
	}
	else
	{
		rep(i,n)
		{
			cout<<n-i<<' '<<res[i]+1<<endl;
		}
	}
	return 0;
}