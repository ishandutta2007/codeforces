#include <iostream>
using namespace std;
struct MC {
	long long val=0;
	long long cost=0;
};
MC dp[300001];
MC dp1[300001];
MC dp2[300001];
int main()
{
	int t, n, x,MaxD,MaxL,d,h;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> x;
		MaxD =MaxL= 0;
		for (int j = 0; j < n; ++j) {
			cin >> d >> h;
			if (d - h > MaxL)MaxL = d - h;
			if (d > MaxD)MaxD = d;
		}
		if (0<MaxL || MaxD >= x) {
			if (MaxD >= x)cout << 1 << "\n";
			else {
				cout << (1 + (x - MaxD + MaxL - 1) / MaxL) << "\n";
			}
		}
		else cout << -1 << "\n";
		
	}
	return 0;
}