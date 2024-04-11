#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int T,n; 
int a[28]; 
char b[100001];
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
int main()
{
	T=read();
	while (T--)
	{
		n=read();
		memset(a,0,sizeof(a));
		for (int i=1;i<=n;i++)
		{
			cin >> b;
			for (int j=0;j<strlen(b);j++)
			{
				a[b[j]-'a']++;
			}
		}
		for (int i=0;i<=25;i++)
		{
			if (a[i]%n!=0)
			{
				cout << "NO" << endl;
				goto no;
			}
		}
		cout << "YES" << endl;
		no:;
	}
	return 0;
}