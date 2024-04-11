#include<iostream>
#include<vector>
using namespace std;

#define int long long


#define pb push_back


signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	char a;
	int h = 0, m = 0;
	cin >> a; h += 10 * (a - '0');
	cin >> a; h += (a - '0');
	cin >> a;
	cin >> a; m += 10 * (a - '0');
	cin >> a; m += (a - '0');
	int h1 = 0, m1 = 0;
	cin >> a; h1 += 10 * (a - '0');
	cin >> a; h1 += (a - '0');
	cin >> a;
	cin >> a; m1 += 10 * (a - '0');
	cin >> a; m1 += (a - '0');
	int need = (h * 60 + m + h1 * 60 + m1) / 2;
	h = need / 60, m = need % 60;
	cout << h / 10 << h % 10 << ":" << m / 10 << m % 10;
}