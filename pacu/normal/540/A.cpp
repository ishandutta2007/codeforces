#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string A;
	string B;
	int N;
	cin >> N >> A >> B;
	int ans = 0;
	for(int i=0;i<N;i++)
		ans += min(abs(10+A[i]-B[i])%10,abs(10+B[i]-A[i])%10);
	cout << ans << endl;
}