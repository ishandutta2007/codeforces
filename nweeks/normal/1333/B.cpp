#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

bool solve(void)
{
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> want(n);

	int cnt[3] = {0,0,0};
	for (auto &v : arr)
	{
		cin >> v;
		cnt[v+1]++;
	}
	for (auto &v : want)
		cin >> v;

	for (int i(n-1); i >= 0; --i)
	{
		cnt[arr[i]+1]--;
		if (arr[i] < want[i] and cnt[2]==0)
			return false;
		if (arr[i] > want[i] and cnt[0]==0)
			return false;
	}
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << (solve() ? "YES\n" : "NO\n");
}