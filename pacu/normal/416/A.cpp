#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	int high = 2000000000;
	int low = -2000000000;
	cin >> N;
	string s;
	int x;
	char c;
	for(int i=0;i<N;i++)
	{
		cin >> s >> x >> c;
		if(((s==">=")&&(c=='Y')) ||
			((s=="<")&&(c=='N')))
			low = max(low,x);
		if(((s==">=")&&(c=='N')) ||
			((s=="<")&&(c=='Y')))
			high = min(high,x-1);
		if(((s==">")&&(c=='Y')) ||
			((s=="<=")&&(c=='N')))
			low = max(low,x+1);
		if(((s==">")&&(c=='N')) ||
			((s=="<=")&&(c=='Y')))
			high = min(high,x);
	}
	if(high < low)
		cout << "Impossible" << endl;
	else
		cout << low << endl;
	return 0;
}