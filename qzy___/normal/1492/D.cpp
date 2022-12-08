#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6e5 + 1;
int a, b, k, p[N], q[N], t;
signed main()
{
	ios::sync_with_stdio(false);
	cin >> a >> b >> k;
	if(a == 0) {
		if(k == 0) {
			cout << "Yes" << "\n";
			for(int i = 1; i <= b; i++)
				cout << '1';
			cout << "\n";
			for(int i = 1; i <= b; i++)
				cout << '1'; 
			cout << "\n";
		}
		else
			cout << "No" << "\n";
		return 0;
	}
	if(b == 1) {
		if(k)
			cout << "No";
		else {
			cout << "Yes" << "\n";
			for(int i = 1; i <= 2; i++) {
				cout << 1;
				for(int j = 1; j <= a; j++)
					cout << 0;
				cout << '\n';
			}
		}
		return 0;
	}
	if(k > a + b - 2)
		return cout << "No", 0;
	cout << "Yes" << "\n", p[2] = q[2 + k] = 1 , t = b - 1;
	for(int i = 1; i <= a + b; i++)
		if(!p[i] && !q[i] && t)
			p[i] = q[i] = 1, t--;
	for(int i = 1; i <= a + b; i++)
		cout << p[i];
	cout << "\n";
	for(int i = 1; i <= a + b; i++)
		cout << q[i];
	return 0;
}