#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k;
	bool bad=1,bad2=1,bad3=1;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1];
		bad&=k<'A'||k>'Z';
		bad2&=k<'a'||k>'z';
		bad3&=k<'0'||k>'9';
	}
	if(n>=5&&!bad&&!bad2&&!bad3)
	{
		printf("Correct\n");
	}
	else
	{
		printf("Too weak\n");
	}
}