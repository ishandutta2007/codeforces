#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = s.size();
	for(int i=0;i<26;i++)
	{
		int maxDist = 0;
		int pre = -1;
		for(int j=0;j<s.size();j++)
			if(s[j]-'a' == i)
			{
				maxDist = max(maxDist,j-pre);
				pre = j;
			}
		maxDist = max(maxDist,(int)s.size()-pre);
		ans = min(ans,maxDist);
	}
	cout << ans << '\n';
}