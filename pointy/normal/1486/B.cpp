#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=100001;
int n,m,T; 
ll x[N],y[N];

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
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	if (n%2==1)
	{
		cout << 1 << endl;
		return;
	}
	sort(x+1,x+n+1);
	int t=n/2;
	sort(y+1,y+n+1);
	ll x1=x[t+1]-x[t]+1,y1=y[t+1]-y[t]+1;
	cout << x1*y1 << endl;
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