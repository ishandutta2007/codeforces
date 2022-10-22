#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=200008;
int a[N],b[N],s[N],p[N];
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
bool check(int x)
{
	for (int i=1;i<=n;i++) 
	{
		if (a[i]>=x) b[i]=1;
		else b[i]=-1;
	}
	for (int i=1;i<=n;i++) s[i]=s[i-1]+b[i];
	p[0]=0;
	for (int i=1;i<=n;i++) p[i]=min(p[i-1],s[i]);
	int res=-100000000;
	for (int i=k;i<=n;i++)
	{
		res=max(res,s[i]-p[i-k]);
	}
	if (res>0) return 1;
	return 0; 
}
int main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)==1) l=mid+1;
		else r=mid-1;
	}
	cout << r << endl;
	return 0;
}