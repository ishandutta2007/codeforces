#include<bits/stdc++.h>
using namespace std;
int T,n; 
int a[30005];
int work(int l,int r)
{
	if (l>r) return 0; 
	if (l==r) 
	{
		if (a[l]==0) return 0;
		return 1;
	}
	int minn=1e9+7;
	for (int i=l;i<=r;i++)minn=min(minn,a[i]);
	for (int i=l;i<=r;i++) a[i]-=minn;
	int last=l,res=0;
	for (int i=l;i<=r;i++)
	{
		if (a[i]==0) 
		{
			res+=work(last,i-1);
			last=i+1;
		}
	}
	res+=work(last,r);
	for (int i=l;i<=r;i++) a[i]+=minn;
	return min(res+minn,r-l+1);
}
inline int read()
{
	char C;
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
int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	cout << work(1,n);
	return 0;
}