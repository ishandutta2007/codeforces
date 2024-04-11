#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
	int N,P;
	long long ap = 0;
	cin >> N >> P;
	for(int i=0;i<N;i++)
	{
		cin >> s;
		if(s.size()==8) ap += (1LL<<((long long)i));
	}
	long long ans = 0;
	for(int i=0;i<N;i++)
	{
		ans += (P*ap)/2;
		ap /= 2;
	}
	cout << ans << '\n';
}