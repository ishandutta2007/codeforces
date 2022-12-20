#include <iostream>
#include <string>
using namespace std;

int N,t;
string s;

int main()
{
	cin >> N >> t;
	cin >> s;
	bool roundup = 0;
	int cut = s.size();
	int i;
	for(i=0;s[i]!='.';i++)
		;
	for(i++;i<s.size() && s[i]<'5';i++)
		;
	if(i==s.size()) i--;
	for(;s[i]!='.';i--)
	{
		if(roundup)
		{
			if(s[i]=='9') s[i] = '0';
			else
			{
				s[i] = (char)(s[i]+1);
				roundup = 0;
			}
		}
		if(s[i] >= '5' && t)
		{
			cut = i;
			roundup = 1;
			t--;
		}
	}
	for(i--;i>=0;i--)
	{
		if(roundup)
		{
			if(s[i]=='9') s[i] = '0';
			else
			{
				s[i] = (char)(s[i]+1);
				roundup = 0;
			}
		}
	}
	if(roundup) cout << 1;
	for(;s[cut-1]=='0';cut--)
		;
	if(s[cut-1]=='.') cut--;
	for(i=0;i<cut;i++)
		cout << s[i];
	cout << '\n';
}