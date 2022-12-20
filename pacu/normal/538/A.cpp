#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cstdio>
using namespace std;

bool equals(string s)
{
	string t = "CODEFORCES";
	if(s.size() != t.size()) return 0;
	for(int i=0;i<s.size();i++)
		if(s[i]!=t[i])
			return 0;
	return 1;
}

int main()
{
	string s;
	string n;
	cin >> s;
	for(int i=0;i<s.size();i++)
		for(int j=i;j<s.size();j++)
		{
			n = "";
			for(int k=0;k<i;k++)
				n += s[k];
			for(int k=(j+1);k<s.size();k++)
				n += s[k];
			if(equals(n))
			{
				cout << "YES\n";
				return 0;
			}
		}
	cout << "NO\n";
	return 0;
}