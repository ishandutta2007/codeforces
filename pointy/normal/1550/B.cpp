#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 
//const ll mod=1000000007;
//const ll mod=998244353;

const int N=201;
int n,x,y,T; 
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
	n=read(),x=read(),y=read();
	for (int i=1;i<=n;i++) cin >> a[i];
	if (y>=0) 
	{
		cout << (x+y)*n << endl;
		return;
	}
	int ans=3;
	for (int i=2;i<=n;i++)
	{
		if (a[i]!=a[i-1]) ans++;
	}
	cout << n*x+ans/2*y << endl;
	return;
}
// 1 1
// 2 2
// 3 2
// 4 3
int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}