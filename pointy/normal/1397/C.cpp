#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n; 
ll a[100005];
int main()
{
	cin >> n;
	if (n==1)
	{
		cout << "1 1\n0\n1 1\n0\n1 1\n";
		int x;
		cin >> x;
		cout << -x;
		return 0;
	}
	for (int i=1;i<=n;i++) cin >> a[i];
	cout << "1 " << n << endl;
	cout << "0 ";
	for (int i=2;i<=n;i++) cout << -a[i]*n << " ";
	cout << endl;
	cout << "2 " << n << endl;
	for (int i=2;i<=n;i++) cout << a[i]*(n-1) << " ";
	cout << "\n1 1\n";
	cout << -a[1];
	return 0;
}