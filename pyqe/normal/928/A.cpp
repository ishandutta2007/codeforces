#include <bits/stdc++.h>

using namespace std;

long long n;
string os;

inline string op(string s)
{
	long long i,ln=s.length();
	
	for(i=0;i<ln;i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			s[i]+='a'-'A';
		}
		if(s[i]=='0')
		{
			s[i]='o';
		}
		if(s[i]=='1'||s[i]=='l')
		{
			s[i]='i';
		}
	}
	return s;
}

int main()
{
	long long i;
	string s;
	
	cin>>os;
	os=op(os);
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		if(op(s)==os)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}