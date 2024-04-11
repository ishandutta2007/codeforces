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
		set<int> nums;
		for (int i = 1; i * i <= n; i++)
			nums.insert(i * i);
		for (int i = 1; i * i * i <= n; i++)
			nums.insert(i * i * i);
		cout << nums.size() << "\n";
	}
	return 0;
}