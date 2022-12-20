#include <iostream>
using namespace std;

int main()
{
	int a,b,t;
	cin >> a >> b;
	for(t=1;;t++)
	{
		if(a<=b) a++, b-=2;
		else a-=2, b++;
		//cout << a << ' ' << b << '\n';
		if(a<0) t--;
		if(b<0) t--;
		if(a<=0) break;
		if(b<=0) break;
	}
	cout << t << '\n';
}