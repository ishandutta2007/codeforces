#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;

	ll ans(0);

	ll prefix(0);
	map<ll, int> lst;
	lst[0] = 0;

	ll cur = 0;
	for (int i(0); i < n; ++i)
	{
		prefix += arr[i];
		if (lst.find(prefix) != lst.end() and lst[prefix] >= cur)
			cur = lst[prefix]+1;
		lst[prefix] = i+1;
		if (i >= cur)
			ans += i-cur+1;
	}
	cout << ans << endl;
}