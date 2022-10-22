#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[201]; 
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
	int T=read();
	while (T--)
	{
		cin >> n >> m;
		for (int i=1;i<=100;i++) a[i]=0;
		int tot=0;
		for (int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			a[x]=1;
		}
		for (int i=1;i<=m;i++)
		{
			int x=read();
			if (a[x]==1) tot++;
		}
		cout << tot << endl;
	}
	return 0;
}