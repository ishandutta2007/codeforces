#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3+1;

bool seen[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;
	list<int> ans;
	for (int i(n-1); i >= 0; --i)
		if (!seen[arr[i]])
		{
			seen[arr[i]] = true;
			ans.push_front(arr[i]);
		}
	cout << ans.size() << endl;
	for (auto e : ans)
		cout << e << ' ';
}