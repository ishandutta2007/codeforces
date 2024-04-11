#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a,b;
	cin >> a >> b;
	int N;
	cout << a << ' ' << b << '\n';
	cin >> N;
	for(int i=0;i<N;i++)
	{
		string s,t;
		cin >> s >> t;
		if(s==a) a = t;
		else b = t;
		cout << a << ' ' << b << '\n';
	}
}