#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m;
	cin >> m;
	vector<int> ans;
	for(int i=1;i<=1000000;i++)
	{
		int z = 0;
		int cur = i;
		while(cur > 0)
		{
			z += cur/5;
			cur /= 5;
		}
		if(z==m) ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << ' ';
	cout << '\n';
}