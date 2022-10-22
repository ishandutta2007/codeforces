#include<bits/stdc++.h>
using namespace std;
int n,m; 

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
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			int x=read();
			if ((i+j)%2==0) cout << "720720 ";
			else cout << 720720-x*x*x*x << " ";
		}
		cout << endl;
	}
	return 0;
}