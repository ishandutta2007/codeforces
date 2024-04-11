#include <iostream>

using namespace std;

int main()
{
	int n,m;
	int ai;
	int cnt=0;
	int rem=0;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> ai;
		if((rem+ai)<=m)
		{
			rem += ai;
		}
		else
		{
			rem = ai;
			cnt++;
		}
	}
	if(rem) cnt++;
	cout << cnt << endl;
}