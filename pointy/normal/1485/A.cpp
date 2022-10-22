#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

const int N=100001;
int n,m,T,ans; 

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

int tot(int x,int y)
{
	int res=0;
	while (1)
	{
		x/=y;
		res++;
		if (x==0) return res;
	}
}
void work()
{
	int a=read(),b=read();
	if (a/b==0) 
	{
		ans=1;
		return;
	}
	ans=1e9;
	for (int i=b;i<=b+31;i++)
	{
		if (i==1) continue;
		if (i-b>ans) return;
		ans=min(ans,tot(a,i)+i-b);
	}
}

int main()
{
	T=read();
	while (T--)
	{
		work();
		printf("%d\n",ans);
	}
	return 0;
}