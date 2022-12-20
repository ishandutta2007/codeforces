#include <iostream>
using namespace std;

int main()
{
	int a,b,n;
	cin >> n >> a;
	int ans = 0;
	int cur = 1;
	for(int i=1;i<n;i++)
	{
		cin >> b;
		if(b < a)
		{
			ans = max(ans,cur);
			cur = 0;
		}
		cur++;
		a = b;
	}
	ans = max(ans,cur);
	cout << ans << '\n';
}