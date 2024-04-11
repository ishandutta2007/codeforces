#include <iostream>
using namespace std;

int main()
{
	long long a,b,c,l;
	cin >> a >> b >> c >> l;
	long long ways = ((l+3)*(l+1)*(l+2))/6;
//	cout << ways << '\n';
	for(int i=0;i<=l;i++)
		if(a+i >= b+c)
		{
			ways -= min(((l+2-i)*(l+1-i))/2,((a+i+2-b-c)*(a+i+1-b-c))/2);
//			cout << '\t' << min(((l-i)*(l+1-i))/2,((a+i+2-b-c)*(a+i+1-b-c))/2) << '\n';
		}
	for(int i=0;i<=l;i++)
		if(b+i >= a+c)
			ways -= min(((l+2-i)*(l+1-i))/2,((b+i+2-a-c)*(b+i+1-a-c))/2);
	for(int i=0;i<=l;i++)
		if(c+i >= a+b)
			ways -= min(((l+2-i)*(l+1-i))/2,((c+i+2-a-b)*(c+i+1-a-b))/2);
	cout << ways << '\n';
	
}