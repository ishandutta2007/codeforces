#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n == 1) cout << 9 << endl;
		else{
		cout << 98;
		for (int i(2); i < n; ++i)
			cout << (8 + i - 1) % 10;
		cout << endl;
		}
	}
}