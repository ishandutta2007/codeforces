#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=824288;
int k,n,m;
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
	for (int i=1;i<=n;i++) a[i]=read();
	return;
}
int sum[N];
void push_up(int u)
{
	if (a[u]=='1') sum[u]=sum[u*2];
	else if (a[u]=='0') sum[u]=sum[u*2+1];
	else sum[u]=sum[u*2]+sum[u*2+1];
}
void build(int u)
{
	if (u>n) 
	{
		sum[u]=1;
		return;
	}
	build(u*2);
	build(u*2+1);
	push_up(u);
}
void change(int u)
{
	while (u)
	{
		push_up(u);
		u/=2;
	}
}
int main()
{
	cin >> k;
	n=1;
	for (int i=1;i<=k;i++) n*=2;
	n--;
	for (int i=1;i<=n;i++) cin >> a[n-i+1];
	m=read();
	build(1);
	while (m--)
	{
		int x=read();
		x=n-x+1;
		char p;
		cin >> p;
		a[x]=p;
		change(x);
		printf("%d\n",sum[1]);
	}
	return 0;
}