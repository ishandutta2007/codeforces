#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, S;
	cin >> N >> S;
	if (2 * N <= S)
	{
		cout << "YES\n";
		for (int i(0); i < N-1; ++i)
			cout << 1 << ' ';
		cout << S-N+1 << '\n' << N << '\n';
		return 0;
	}
	cout << "NO\n";
}