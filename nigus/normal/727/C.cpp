#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define allP(x) x->begin(), x->end()
#define sz(x) (int)(x).size()

// #define int ll

typedef long long ll;

const int inf = 0x3f3f3f3f;
const long long mod = 1000000007;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin.exceptions(cin.failbit);
	// cout << setprecision(10);
	// cout << fixed;

	int n; cin >> n;
	vector<int> arr(n);

	int a1, a2, a3;
	cout << "? 1 2\n" << flush; cin >> a1;
	cout << "? 2 3\n" << flush; cin >> a2;
	cout << "? 1 3\n" << flush; cin >> a3;

	int index1 = (a1 + a2 - a3) / 2;

	arr[1] = index1;
	arr[0] = a1 - index1;
	arr[2] = a2 - index1;

	for (int i = 3; i < n; i++)
	{
		cout << "? 2 " << (i + 1) << "\n" << flush;
		int temp; cin >> temp;

		arr[i] = temp - index1;
	}

	cout << "! ";
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}

	cout << flush;

	return 0;
}