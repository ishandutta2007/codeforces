#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long T,x,y,p,q;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> x >> y >> p >> q;
		if(p==0)
		{
			if(x==0) cout << 0 << '\n';
			else cout << -1 << '\n';
			continue;
		}
		if(p==q)
		{
			if(x==y) cout << 0 << '\n';
			else cout << -1 << '\n';
			continue;
		}
		long long low = x/p;
		while(low*p < x) low++;
		long long low2 = (y-x)/(q-p);
		while(low2*(q-p) < (y-x)) low2++;
		cout << max(low,low2)*q-y << '\n';
	}
}