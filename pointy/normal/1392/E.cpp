#include<bits/stdc++.h>
using namespace std;
int n;
#define ll long long
long long a[30][30];
long long po[60];
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
	cin >> n;
	po[0]=1;
	for (int i=1;i<=60;i++) po[i]=po[i-1]*(ll)2;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (j%2==1) cout << "0";
			else cout << po[i+j-3];
			cout << " ";
		}
		cout << endl;
		fflush(stdout);
	}
	int q;
	cin >> q;
	while (q--)
	{
		long long c,x=1,y=1;
		cin >> c;
		cout << "1 1\n";
		fflush(stdout);
		while (1)
		{
			int d=c%2;
			if (y%2==1&&d==1) y++;
			else if (y%2==1) x++;
			else if (d==1) x++;
			else y++;
			cout << x << " " << y << endl;
			fflush(stdout);
			if (x==n&&y==n) break;
			c/=2;
		}
	}
	return 0;
}