#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int T,n,x; 
char s[100005],w[100005];
inline int read()
{
	char C;
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
int f(int x)
{
	if (x<0) return n;
	if (x>n-1) return n;
	return x;
}
int main()
{
	T=read();
	while (T--)
	{
		cin >> s;
		x=read();
		n=strlen(s);
		for (int i=0;i<n;i++) w[i]='1';
		w[n]='0';
		for (int i=0;i<n;i++)
		{
			if (s[i]=='0') 
			{
				w[f(i+x)]='0';
				w[f(i-x)]='0';
			}
		}
		for (int i=0;i<n;i++)
		{
			if (s[i]=='1') 
			{
				if (w[f(i+x)]=='0'&&w[f(i-x)]=='0') 
				{
					cout << "-1" << endl;
					goto no;
				}
			}
		}
		for (int i=0;i<n;i++) cout << w[i];
		cout << endl;
		no:;
	}
	return 0;
}