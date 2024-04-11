#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ull bas=37;
const int N=1e5+5;
int n,tp;
char a[N];
ull b[N],c[N],p[N];
inline ll read()
{
    ll F=1,ANS=0;
	char C=getchar();
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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
bool check(int l,int r)
{
	ull x=b[r]-b[l-1]*p[r-l+1];
	ull y=c[l]-c[r+1]*p[r-l+1];
	return (x==y);
}
int s[5015][5015];
int main()
{
	tp=0;
	cin >> (a+1);
	n=strlen(a+1);
	for (int i=1;i<=n;i++) b[i]=b[i-1]*bas+a[i]-'a';
	for (int i=n;i>=1;i--) c[i]=c[i+1]*bas+a[i]-'a';
	p[0]=1;
	for (int i=1;i<=n;i++) p[i]=p[i-1]*bas;
	if (n<=5014)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i;j<=n;j++)
			{
				s[i][j]=check(i,j);
			}
		}
		for (int i=2;i<=n;i++)
		{
			for (int j=1;j<=n-i+1;j++)
			{
				int l=j,r=j+i-1;
				s[l][r]+=s[l+1][r]+s[l][r-1]-s[l+1][r-1];
			}
		}
		int q=read();
		ll lastans=0;
		while (q--)
		{
			ll l=read(),r=read();
			if (tp) l^=lastans,r^=lastans;
			lastans=s[l][r];
			printf("%lld\n",lastans);
		}
		return 0;
	}
	else
	{
		int q=read();
		ll l=read(),r=read();
		ll L=read(),R=read();
		ll ans=(L^l);
		while (q--) printf("%lld\n",ans);
	}
	return 0;
}