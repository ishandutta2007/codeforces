#include <iostream>
using namespace std;

int main()
{
	int a,b;
	int cnt = 0;
	cin >> a >> b;
	while(a&&b&&((a+b)>=3))
	{
		a--,b--,cnt++;
		if(a>b) a--;
		else b--;
	}
	cout << cnt << endl;
	return 0;
}