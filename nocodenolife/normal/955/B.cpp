#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	string s;
	cin>>s;

	if(s.length()<=3)
	{
		cout<<"No";
		return 0;
	}

	int cal[26] = {0};

	for(int i=0;i<s.length();i++)
	{
		cal[(int)(s[i]-'a')]++;
	}
	int one = 0;
	int tot = 0;
	for(int i=0;i<26;i++)
	{
		if(cal[i]>1)
			tot++;
		else if(cal[i]==1)
		{
			one++;
			tot++;
		}
	}
	if(tot>4)
	{
		cout<<"No";
		return 0;
	}
	else if(tot>2)
	{
		cout<<"Yes";
		return 0;
	}
	else if(tot==2)
	{
		if(one==0)
			cout<<"Yes";
		else
			cout<<"No";
		return 0;
	}
	else
	{
		cout<<"No";
		return 0;
	}

    return 0;
}