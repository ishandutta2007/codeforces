#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t , a , b;

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		if(a > b)
			swap(a , b);
		if(a == b)
			cout << a + b << endl;
		else if(a + 1 == b)
			cout << a + b << endl;
		else
			cout << a + b + b - a - 1 << endl;
	} 
	return 0;
}