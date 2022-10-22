#include<bits/stdc++.h>
using namespace std;

const int M=100;
int n,a[2000005],f[M],ans[2000005],b[2000005],p[M],sum;

int len(int a)//a2
{
	int ans=0;
	while(a)
		ans++,a/=2;
	return ans;
}

void add(int a)
{
	int k=len(a),r=a;
	while (f[k]!=0&&r!=0)
		r=f[k]^r,k=len(r);
	if (r!=0)
		f[k]=r,p[++sum]=a;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int pp=1;
	int x=0;sort(a+1,a+1+n);
	for (int i=1;i<=30;i++)
	{
		while(pp<=n&&a[pp]<(1<<i))
			add(a[pp++]);
		if (sum==i)
			x=i;
	}
	cout<<x<<endl;
	for (int i=1;i<=x;i++)
		for (int j=(1<<(i-1));j<(1<<x);j+=(1<<i))
			ans[j]=p[i];
	cout<<0<<' ';
	for (int i=1;i<(1<<x);i++)
		b[i]=ans[i]^b[i-1],cout<<b[i]<<' ';
	return 0;
}