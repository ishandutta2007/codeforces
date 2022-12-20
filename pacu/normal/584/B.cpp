#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 1;
	for(int i=0;i<3*n;i++)
		ans = (3LL*ans)%1000000007;
	int k = 1;
	for(int i=0;i<n;i++)
		k = (7LL*k)%1000000007;
	cout << (1000000007+ans-k)%1000000007 << '\n';
	
}