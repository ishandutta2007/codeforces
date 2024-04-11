#include<bits/stdc++.h>
using namespace std;
int t; 
int x,y;
string s;
int a[10];
inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
int main()
{
	t=read();
	while (t--)
	{
		x=read(),y=read();
		cin >> s;
		memset(a,0,sizeof(a));
		for (int i=0;i<s.length();i++)
		{
			if (s[i]=='U') a[1]++;
			else if (s[i]=='D') a[2]++;
			else if (s[i]=='R') a[3]++;
			else if (s[i]=='L') a[4]++;
		}
		bool ans=1;
		if (x>=0)
		{
			if (a[3]>=x);
			else ans=0;
		}
		else
		{
			if (a[4]>=-x);
			else ans=0;
		}
		if (y>=0)
		{
			if (a[1]>=y);
			else ans=0;
		}
		else
		{
			if (a[2]>=-y);
			else ans=0;
		}
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}