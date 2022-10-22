#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))

const int N=200001;
ll ans;
int n,q,k; 
ll a[N];

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

void work(int l,int r)
{
	if (l==r)
	{
		ans=k-1;
		return;
	}
	ans=(r-l+1)*(-2)+1-a[l]+a[r]+k;
	/*
	for (int i=l;i<=r;i++)
	{
		if (i==l) ans+=a[i+1]-2;
		else if (i!=r)ans+=a[i+1]-a[i-1]-2;
		else ans+=k-a[i-1]-1;
	}
	*/
	return;
}
// .....
// -0001
int main()
{
	n=read(),q=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	while (q--)
	{
		int l=read(),r=read();
		work(l,r);
		printf("%lld\n",ans);
	}
	return 0;
}