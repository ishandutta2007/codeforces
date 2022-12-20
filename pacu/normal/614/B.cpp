#include <iostream>
#include <string>
using namespace std;

string s[100000];
int N;

int main()
{
	cin >> N;
	int bad = -1;
	int zero = 0;
	bool null = 0;
	for(int i=0;i<N;i++)
	{
		cin >> s[i];
		if(s[i].size()==1 && s[i][0]=='0')
			null = 1;
		int cnt1 =0;
		for(int j=0;j<s[i].size();j++)
		{
			if(s[i][j]=='0') continue;
			else if(s[i][j]=='1') cnt1++;
			else bad = i;
		}
		if(cnt1>1) bad = i;
		if(bad!=i)
		{
			for(int j=0;j<s[i].size();j++)
				if(s[i][j]=='0')
					zero++;
		}
	}
	if(null)
	{
		cout << 0 << '\n';
		return 0;
	}
	if(bad==-1)
	{
		cout << 1;
		for(int i=0;i<zero;i++)
			cout << 0;
		cout << '\n';
		return 0;
	}
	cout << s[bad];
	for(int i=0;i<zero;i++)
		cout << '0';
	cout << '\n';
}