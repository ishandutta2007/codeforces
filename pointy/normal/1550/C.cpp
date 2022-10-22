#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 
//const ll mod=1000000007;
//const ll mod=998244353;

const int N=200001;
int n,m,T; 
int a[N];
int check(int l,int r,int len)
{
	for (int i=l;i<=r;i++)
	{
		for (int j=i+1;j<=r;j++)
		{
			for (int k=j+1;k<=r;k++)
			{
				if (a[i]<=a[j]&&a[j]<=a[k]) return 0;
				if (a[i]>=a[j]&&a[j]>=a[k]) return 0;
			}
		}
	}
	return 1;
}
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
	int ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int len=1;len<=4;len++)
	{
		for (int i=1;i<=n-len+1;i++)
		{
			int j=i+len-1;
			if (len<=2) 
			{
				ans++;
				continue;
			}
			ans+=check(i,j,len);
		}
	}
	cout << ans << endl;
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