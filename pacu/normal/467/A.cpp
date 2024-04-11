#include <iostream>
using namespace std;

int main()
{
	int N;
	int ans = 0;
	cin >> N;
	int a,b;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		ans += (b-a)>=2;
	}
	cout << ans << endl;
	return 0;
}