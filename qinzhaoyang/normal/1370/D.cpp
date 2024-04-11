#include <iostream>

using namespace std;

int n , k;
int a[200010];

bool check(int x , int f)
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(f)
		{
			if(a[i] <= x)
			{
				cnt++;
				f = !f;
			}
		}
		else
		{
			cnt++;
			f = !f; 
		}
	}
	if(cnt >= k)
		return true;
	return false;
}

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)	
		cin >> a[i];
	int l = 0 , r = 1000000000;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(check(mid , true) || check(mid , false))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << endl;
	return 0;
}