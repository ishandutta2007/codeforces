#include <iostream>
#include <algorithm>

using namespace std;

int n , m;
long long k , a[200010];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		m = 0;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
		{
			int temp;
			cin >> temp;
			if(temp % k != 0) 
				a[++m] = (k - temp % k) % k;
		}
		if(m == 0)
		{
			cout << 0 << endl;
			continue;
		}
		sort(a + 1 , a + m + 1);
		long long cnt = 0 , max1 = 0;
		for(int i = 1; i <= m; i++)
		{
			if(i != 1 && a[i] != a[i - 1])
			{
				max1 = max(max1 , a[i - 1] + (cnt - 1) * k);
				cnt = 0;
			}
			cnt++;
		}
		max1 = max(max1 , a[m] + (cnt - 1) * k);
		cout << max1 + 1 << endl;
	}
	return 0;
}