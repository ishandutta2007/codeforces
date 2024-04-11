#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;

int cnt[26];

int main()
{
	cin >> s;
	for(int i=0;i<s.size();i++)
		cnt[s[i]-'a']++;
	int nzero = 0;
	for(int i=0;i<26;i++)
		if(cnt[i])
			nzero++;
	if(nzero == 2)
	{
		for(int i=0;i<26;i++)
			if(cnt[i]==1)
			{
				cout << "NO\n";
				return 0;
			}
		cout << "YES\n";
		return 0;
	}
	if(nzero == 3)
	{
		for(int i=0;i<26;i++)
			if(cnt[i]>1)
			{
				cout << "YES\n";
				return 0;
			}
		cout << "NO\n";
		return 0;
	}
	if(nzero == 4)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}