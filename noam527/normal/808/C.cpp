#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, w, a[101], ans[101], tot = 0; cin >> n >> w;
	for (int i = 0; i < n; i++) cin >> a[i], ans[i] = (a[i] + 1) / 2, tot += ans[i];
	if (tot > w)
	{
		cout << -1 << endl;
		return 0;
	}
	int maxp, maxf, prev;
	while (tot < w)
	{
		maxf = 0;
		for (int i = 0; i < n; i++) if (ans[i] != a[i] && a[i] > maxf) maxf = a[i], maxp = i;
		prev = ans[maxp];
		ans[maxp] = min(a[maxp], ans[maxp] + w - tot);
		tot += ans[maxp] - prev;
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0;
}