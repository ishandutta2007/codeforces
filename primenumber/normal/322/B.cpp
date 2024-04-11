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
	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(),a.end());
	int m = a[0];
	int s = 0;
	if(m >= 3)
	{
		s += m-3;
		a[0]-=m-3;a[1]-=m-3;a[2]-=m-3;
	}
	int mm = 0;
	rep(i,(a[0]+1))
	{
		if(mm < (a[1]-i)/3+(a[2]-i)/3+i)
			mm =  (a[1]-i)/3+(a[2]-i)/3+i;
	}
	cout << s+mm << endl;
	return 0;
}