#include <iostream>

using namespace std;

int main()
{
	int n;
	char a , b;
	int cnt1 = 0 , cnt2 = 0;
	cin >> n >> a;
	for(int i = 2; i <= n; i++)
	{
		cin >> b;
		if(a != b && b == 'F')
			cnt2++;
		else if(a != b)
			cnt1++;
		a = b;
	}
	if(cnt2 > cnt1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}