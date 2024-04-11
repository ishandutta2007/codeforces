#include <iostream>
#include <iomanip>
using namespace std;

int sans(int n,int low)
{
	if(n < 2*low) return -1;
	return n/(2*low);
}

int main()
{
	int a,b;
	cin >> a >> b;
	if(a < b)
	{
		cout << -1 << '\n';
		return 0;
	}
	int k1 = sans(a-b,b);
	int k2 = sans(a+b,b);
	double ans;
	if(k1==-1 && k2==-1)
	{
		cout << -1 << '\n';
		return 0;
	}
	else if(k1==-1) ans = ((a+b)/(2.0*k2));
	else if(k2==-1) ans = ((a-b)/(2.0*k1));
	else ans = min(((a-b)/(2.0*k1)),((a+b)/(2.0*k2)));
	cout << setprecision(20) << fixed << ans << '\n';
}