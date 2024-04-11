#include <iostream>
#include <string>
using namespace std;

string s;
int k,n;

int main()
{
	cin >> s >> k;
	n = s.size();
	if(n%k)
	{
		cout << "NO\n";
		return 0;
	}
	k = n/k;
	for(int i=0;i<n;i++)
	{
		if(s[k*(i/k)+(i%k)] != s[k*(i/k)+k-1-(i%k)])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}