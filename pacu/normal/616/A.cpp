#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void ans(char tp)
{
	cout << tp << '\n';
	exit(0);
}


int main()
{
	ios::sync_with_stdio(0);
	string s,t;
	cin >> s >> t;
	int i = 0;
	while(i!=s.size()-1 && s[i]=='0')
		i++;
	s = s.substr(i,string::npos);
	i = 0;
	while(i!=t.size()-1 && t[i]=='0')
		i++;
	t = t.substr(i,string::npos);
	if(s.size()<t.size()) ans('<');
	else if(s.size()>t.size()) ans('>');
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<t[i]) ans('<');
		if(s[i]>t[i]) ans('>');
	}
	ans('=');
}