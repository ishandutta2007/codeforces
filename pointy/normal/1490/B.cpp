#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

const int N=100001;
int n,m,T; 
int a[N];
int b[5];

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
	for (int i=1;i<=n;i++) a[i]=read()%3;
	mem(b);
	for (int i=1;i<=n;i++) b[a[i]]++;
	int ans=0;
	for (int i=0;i<=2;i++) 
	{
		if (b[i]>=n/3&&b[(i+1)%3]<=n/3&&b[(i+2)%3]<=n/3) 
		{
			cout << (n/3-b[(i+1)%3])*1+(n/3-b[(i+2)%3])*2 << endl;
			return;
		}
	}
	for (int i=0;i<=2;i++) 
	{
		if (b[i]<=n/3&&b[(i+1)%3]>=n/3&&b[(i+2)%3]>=n/3) 
		{
			cout << (b[(i+1)%3]-n/3)*2+(b[(i+2)%3]-n/3) << endl;
			return;
		}
	}
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