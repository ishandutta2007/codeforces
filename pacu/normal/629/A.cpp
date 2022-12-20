#include <iostream>
#include <string>
using namespace std;

string s[101];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> s[i];
	long long ans = 0;
	for(int i=0;i<N;i++)
	{
		int c = 0;
		int d = 0;
		for(int j=0;j<N;j++)
		{
			c += (s[i][j]=='C');
			d += (s[j][i]=='C');
		}
		ans += (c*(c-1))/2 + (d*(d-1))/2;
	}
	cout << ans << '\n';
}