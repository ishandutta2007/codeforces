#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
bool arr[1000001];
void seive()
{
	for (int i = 2; i < 1000001; i++)
	{
		arr[i] = 1;
	}
 
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (arr[i] == 0)continue;
		for (int j = i + i; j <= 1000000; j += i)arr[j] = 0;
	}
}
int a, b, k;
bool solve(int x)
{
	int cnt = 0;
	for (int i = 0; i < x; i++)
	{
		if (arr[a + i])cnt++;
	}
	if (cnt < k)return false;
	for (int i = x; i+a <= b; i++)
	{
		if (arr[a + i])cnt++;
		if (arr[a + i - x])cnt--;
		if (cnt < k)return false;
	}
	return true;
}
int main()
{
	seive();
	cin >> a >> b >> k;
	int st = 1, en = b - a + 1;
	int ans = -1;
	while (st <= en)
	{
		int mid = (st + en) / 2;
		if (solve(mid))
		{
			ans = mid;
			en = mid - 1;
		}
		else st = mid + 1;
	}
	cout << ans << endl;
	return 0;
}