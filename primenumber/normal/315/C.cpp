#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>

#define rep(i,n)	for(int i = 0;i < n;i++)

using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	list<long long> ary;
	rep(i,n)
	{
		int a;
		cin >> a;
		ary.push_back(a);
	}
	long long difst = 0;
	bool flg = false;
	auto it = ary.begin();
	int j = 0;
	int m = n;
	rep(i,n)
	{
		long long d = difst-j*(m-j-1)*(*it);
		if(d >= k)
		{
			difst += (*it)*j;
			j++;
		}
		else
		{
			cout << i+1 << endl;
			m--;
		}
		it++;
	}
	return 0;
}