#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); 
	int T;
	cin >> T;
	while(T--)
	{
		int n , k;
		cin >> n >> k;
		int t = n / k * k;
		if(n % k != 0)
			t += k;
		if(t % n == 0)
			cout << t / n << endl;
		else
			cout << t / n + 1 << endl;
	}
	return 0;
}