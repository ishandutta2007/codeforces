#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 5000;
int a[MAXN];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	long long ans = 1E18;
	for (int i = 0; i < n; i++)
	{
		long long temp = 0;
		long long prev = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			long long num = prev / a[j] + 1;
			temp += num;
			prev = a[j] * num;
			//cout << "num " << j << " " << num << endl;
		}
		prev = 0;
		for (int j = i + 1; j < n; j++)
		{
			long long num = prev / a[j] + 1;
			temp += num;
			prev = a[j] * num;
			//cout << "num " << j << " " << num << endl;
		}
		ans = min(ans, temp);
		//cout << i << " " << temp << endl;
	}
	cout << ans << "\n";
	return 0;
}