#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> vec;
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			sum += x;
			vec.push_back(x);
		}
		int mx = *max_element(vec.begin(), vec.end());
		sum -= mx;
		cout << fixed << setprecision(7) << mx + ((double) sum / (n - 1)) << "\n";
	}
	return 0;
}