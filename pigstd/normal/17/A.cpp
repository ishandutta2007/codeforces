#include<bits/stdc++.h>
using namespace std;

const int M=1005;
int a[M]={1,1},n,k,sum,p[M],psum;

int main()
{
	cin>>n>>k;
	for (int i=2;i<=n;i++)
		if (!a[i])
		{
			for (int j=i*i;j<=n;j+=i)
				a[j]=1;
			p[++psum]=i;
		}
	for (int i=1;i<=psum;i++)
		if (p[i]+p[i+1]+1<=n)
			if (!a[p[i]+p[i+1]+1])
				sum++;
	if (sum>=k)cout<<"YES";
	else cout<<"NO";
	return 0;
}