#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=500001;
int n,m,T; 
char a[N];

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

void work()
{
	n=read();
	int u=0,v=0;
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i];
		if (a[i]=='1') u++;
		else v++;
	}
	if (n%2==1||u%2==1||a[1]=='0'||a[n]=='0')
	{
		puts("NO");
		return;
	}
	puts("YES");
	int x=0,y=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]=='1')
		{
			x++;
			if (x<=u/2) cout << "(";
			else cout << ")";
		}
		else
		{
			y++;
			if (y%2==0) cout << "(";
			else cout << ")";
		}
	}
	puts("");
	x=0,y=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]=='1')
		{
			x++;
			if (x<=u/2) cout << "(";
			else cout << ")";
		}
		else
		{
			y++;
			if (y%2==0) cout << ")";
			else cout << "(";
		}
	}
	puts("");
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}