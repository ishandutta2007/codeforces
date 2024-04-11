#include <algorithm>
#include <iostream>
using namespace std;
using ll=long long;
const int maxn = int(1e4) + 10;

int n, k;
int p1[maxn];
int a[maxn];

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> k;
	for (int i=2; i<=n; ++i) {
		cout << "or 1 " << i << endl;
		int x; cin >> x;
		cout << "and 1 " << i << endl;
		int y; cin >> y;
		p1[i] = x+y;
	}

	int s23 = 0;
	{ cout << "or 2 3" << endl; int x; cin >> x; s23 += x; }
	{ cout << "and 2 3" << endl; int x; cin >> x; s23 += x; }

	a[1] = (p1[2] + p1[3] - s23)/2;
	for (int i=2; i<=n; ++i) a[i] = p1[i]-a[1];

	sort(a+1, a+n+1);
	cout << "finish " << a[k] << endl;

    return 0;
}