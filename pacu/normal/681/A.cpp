#include <iostream>
using namespace std;

char s[500];
int a,b;
int n;

int main()
{
	cin >> n;
	bool g  =0;
	for(int i=0;i<n;i++)
	{
		cin >> s >> a >> b;
		if(a < b && a >= 2400) g = 1;
	}
	if(g) cout << "YES\n";
	else cout << "NO\n";
}