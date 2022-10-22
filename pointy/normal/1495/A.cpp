#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=200001;
int n,m,T; 
int a[N],b[N];


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
	int cnta=0,cntb=0;
	for (int i=1;i<=2*n;i++) 
	{
		int x=read(),y=read();
		if (x==0) b[++cntb]=abs(y);
		else a[++cnta]=abs(x);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	db ans=0;
	for (int i=1;i<=n;i++)
	{
		db x=(db)a[i],y=(db)b[i];
		ans+=sqrt(x*x+y*y);
	}
	printf("%.13f\n",ans);
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