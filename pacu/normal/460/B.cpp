#include <iostream>
#include <vector>
using namespace std;

long long getDig(long long x)
{
	if(x<10)
		return x;
	else
		return (x%10) + getDig(x/10);
}

int main()
{
	long long a,b,c;
	long long sm,x;
	vector<long long> ans;
	cin >> a >> b >> c;
	for(sm=1;sm<=81;sm++)
	{
		x = pow((long double)sm,(int)a);
		x = b*x;
		x += c;
		if(x>=1000000000)
			continue;
		if(sm==getDig(x))
			ans.push_back(x);
	}
	cout << ans.size() << endl;
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
}