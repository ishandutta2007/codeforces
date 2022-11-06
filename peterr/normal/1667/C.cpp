#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ans = 1;
	int ptr = 1;
	while (n > ptr + 2)
	{
		ptr += 3;
		ans += 2;
	}
	if (n == ptr + 2)
		ans++;
	cout << ans << "\n";
	int top = (ans + 1) / 2;
	for (int i = 0; i < top; i++)
	{
		cout << top - i << " " << 1 + i << "\n";
	}
	if (ans % 2 == 0)
		cout << top + 1 << " " << top + 1 << "\n";
	int bottom = (ans - 1) / 2;
	for (int i = 0; i < bottom; i++)
	{
		cout << ans - i << " " << ans - bottom + 1 + i << "\n";
	}
	return 0;
}