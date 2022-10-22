#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
const ll inf=1000000000000000000; 

const int N=200005;
int n,m,T; 
ll a[N],ansx,ansy,ansz,ansf;

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
	if (n==2)
	{
		for (int i=1;i<=n;i++) cout << a[i] << " ";
		cout << endl;
		return;
	}
	ansx=inf,ansy=0;
	for (int i=1;i<n;i++)
	{
		ansx=min(ansx,a[i+1]-a[i]);
	}
	for (int i=1;i<n;i++)
	{
		if (a[i+1]-a[i]==ansx)
		{
			int p1=1;
			if (i==1) p1=3;
			int p2=n;
			if (i==n-1) p2=n-2;
			ll res=n-3;
			if (a[p1]>=a[i]) res++;
			if (a[p2]<=a[i+1]) res++;
			if (res>=ansy)
			{
				ansy=res;
				ansz=i;
				ansf=0;
			}
		}
	}
	if (ansy==n-1)
	{
		cout << a[ansz] << " ";
		for (int i=1;i<=n;i++)
		{
			if (i!=ansz&&i!=ansz+1) cout << a[i] << " ";
		}
		cout << a[ansz+1] << " ";
		puts("");	
	}
	else
	{
		for (int i=1;i<n;i++)
		{
			if (a[i+1]-a[i]==ansx)
			{
				cout << a[i] << " ";
				for (int j=i+2;j<=n;j++) cout << a[j] << " ";
				for (int j=1;j<i;j++) cout << a[j] << " ";
				cout << a[i+1] << " ";
				puts("");	
				return;
			}
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