#include <iostream>
using namespace std;

int main()
{
	int v1,v2;
	int t,d;
	cin >> v1 >> v2 >> t >> d;
	int dist = 0;
	for(int i=0;i<t;i++)
	{
		dist += v1;
		v1 = min(v2+(t-i-2)*d,v1+d);
	}
	cout << dist << '\n';
}