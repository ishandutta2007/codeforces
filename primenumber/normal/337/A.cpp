#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>

#define rep(i,n)	for(int i = 0;i < (n);i++)
#define rep2(i,n)	for(int i = 1;i <= (n);i++)
#define each(i,x)	for(auto & i : x)

using namespace std;

int main()
{
	int n,m;
	cin >>n>>m;
	vector<int> ary(m);
	rep(i,m)cin>>ary[i];
	sort(ary.begin(),ary.end());
	int mind = 1000000000;
	rep(i,m-n+1)
	{
		mind=min(mind,ary[i+n-1]-ary[i]);
	}
	cout<<mind<<endl;
	return 0;
}