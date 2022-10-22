#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int T,n; 
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
		for (int i=1;i<=2*n-1;i++)
		{
			char x;
			cin >> x;
			if (i%2==1) cout << x;
		}
		cout << endl;
	}
	return 0;
}