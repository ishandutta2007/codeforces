#include <iostream>
using namespace std;

int main()
{
	int n,k;
	int i;
	int a,b;
	int cnt=0;
	cin >> n >> k;
	for(i=0;i<k;i++)
	{
		cin >> a;		
		if(a>0) cnt++;
	}
	cin >> b;
	while(cin&&(b==a))
	{
		if(b>0) cnt++;
		cin >> b;
	}
	cout << cnt << endl;
}