#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int k;
	cin >> k;
	int p(1);
	while (p <= k)
		p *= 2;

	cout << "3 3" << endl;
	cout << p + k << ' ' << k << ' ' << k << endl;
	cout << p << ' ' << k << ' ' << p << endl;
	cout << p << ' ' <<  p + k << ' ' << k << endl;
}