#include<bits/stdc++.h>
using namespace std;
int n,t;
inline int read()
{
	char C;
	long long F=1,ANS=0;
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
		cin >> n;
		int x,y;
		bool flag=0;
		cin >> y;
		for (int i=2;i<=n;i++)
		{
			cin >> x;
			if (x!=y)
			{
				flag=1;
			}
		}
		if (flag) cout << 1 << endl;
		else cout << n << endl;
	}
	return 0;
}