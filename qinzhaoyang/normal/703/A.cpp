#include <iostream>

using namespace std;

int main()
{
	int n , cnt1 = 0 , cnt2 = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a , b;
		cin >> a >> b;
		if(a > b)
			cnt1++;
		else if(b > a)
			cnt2++;
	}
	if(cnt1 > cnt2)
		cout << "Mishka" << endl;
	else if(cnt2 > cnt1)
		cout << "Chris" << endl;
	else
		cout << "Friendship is magic!^^" << endl;
	return 0;
}