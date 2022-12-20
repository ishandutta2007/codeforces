#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;
int l,u,d,r;

int main()
{
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='L') l++;
		if(s[i]=='R') r++;
		if(s[i]=='U') u++;
		if(s[i]=='D') d++;
	}
	if(s.size()%2)
	{
		cout << -1 << '\n';
		return 0;
	}
	int ans = 100000;
	for(int i=0;i<=s.size();i+=2)
	{
		int v1 = i/2;
		int v2 = (s.size()-i)/2;
		ans = min(ans,(abs(l-v1)+abs(r-v1)+abs(u-v2)+abs(d-v2))/2);
	}
	cout << ans << '\n';
}