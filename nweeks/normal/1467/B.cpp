#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 

bool isOK(int a, int b, int c)
{
	return (b > a and b > c) or (b < a and b < c);
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (auto &v : arr) cin >> v;
		int tot(0);
		for (int i(1); i < n-1; ++i)
			if (isOK(arr[i-1], arr[i], arr[i+1]))
				++tot;
		int ret(tot);
		for (int i(0); i < n; ++i)
		{
			int curVal = arr[i];
			vector<int> range = {-1, (int)2e9};
			if (i and i < n-1)
				range.push_back((arr[i-1] + arr[i+1]) / 2);
			if (i) range.push_back(arr[i-1]);
			if (i < n-1) range.push_back(arr[i+1]);

			for (auto v : range)
			{
				int delta(0);
				if (i and i < n-1 and isOK(arr[i-1], arr[i], arr[i+1]))
					delta--;
				if (i > 1 and isOK(arr[i-2], arr[i-1], arr[i]))
					delta--;
				if (i+2 < n and isOK(arr[i], arr[i+1], arr[i+2]))
					delta--;
				arr[i] = v;

				if (i and i < n-1 and isOK(arr[i-1], arr[i], arr[i+1]))
					delta++;
				if (i > 1 and isOK(arr[i-2], arr[i-1], arr[i]))
					delta++;
				if (i+2 < n and isOK(arr[i], arr[i+1], arr[i+2]))
					delta++;
				arr[i] = curVal;
				ret = min(ret, tot + delta);
			}
		}
		cout << ret << '\n';
	}
}