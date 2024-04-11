#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[1000010] , b[1000010];

int check(int x)
{
	int pre = b[1] - x;
	if(pre < 0)
		return -1;
	for(int i = 2; i <= n; i++)
	{
		pre = min(pre , a[i]);
		pre += b[i] - a[i];
		if(pre < 0)
			return -1;
	}
	return pre;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		int l = 0 , r = min(a[1] , b[1]) + 1;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if(check(mid) < 0)
				r = mid;
			else
				l = mid + 1; 
		}
		r--;
		if(r >= 0 && r + check(r) >= a[1])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}