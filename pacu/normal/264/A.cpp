#include <iostream>
#include <string>
using namespace std;
int ans[1000000];
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	int i = 0;
	int j = s.size()-1;
	for(int k=0;k<s.size();k++)
	{
		if(s[k]=='l') ans[j--] = k+1;
		if(s[k]=='r') ans[i++] = k+1;
	}
	for(int k=0;k<s.size();k++)
		cout << ans[k] << "\n";
	return 0;
}