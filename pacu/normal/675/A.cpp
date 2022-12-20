#include <iostream>
using namespace std;


int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	if(c==0 && a==b)
		cout << "YES\n";
	else if(c==0)
		cout << "NO\n";
	else if((b-a)%c)
		cout << "NO\n";
	else if((b-a)/c < 0)
		cout << "NO\n";
	else
		cout << "YES\n";
}