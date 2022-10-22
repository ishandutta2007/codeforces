#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		if (x%2==1) cout << (x+1)/2 << endl;
		else cout << (x+3)/2 << endl;
	}
	return 0;
}