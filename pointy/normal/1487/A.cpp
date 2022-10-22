#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

const int N=100001;
int n,m,T; 
int a[N];

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
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==a[1]) cnt++;
	}
	printf("%d\n",n-cnt);
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