#include <bits/stdc++.h>
using namespace std;
int n,s,tot;
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
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
	n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		tot=0;
		for (int i=1;i<=12;i++)
		{
			tot+=i;
			if (tot>x) 
			{
				s^=(i-1);
				break;
			}
		}
	}
	if (s!=0) cout << "NO";
	else cout << "YES";
	return 0;
}