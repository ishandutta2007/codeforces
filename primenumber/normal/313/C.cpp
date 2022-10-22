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
	int k;
	cin >> k;
	vector<int> vec(k);
	rep(i,k)
	{
		cin >> vec[i];
	}
	sort(vec.begin(),vec.end());
	int l = 1;
	long long int sum = 0;
	while(l <= k)
	{
		rep2(i,l)
		{
			sum += vec[k-i];
		}
		l *= 4;
	}
	cout << sum << endl;
	return 0;
}