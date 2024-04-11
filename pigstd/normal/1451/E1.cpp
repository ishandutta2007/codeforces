#include<bits/stdc++.h>
using namespace std;

const int M=(1<<16)+10;
int a[M],c[M],n,p[M],k1,k2;

int main()
{
	cin>>n;a[1]=0,p[0]=1;
	for (int i=2;i<=n;i++)
	{
		cout<<"XOR 1 "<<i<<endl;cout<<flush;
		cin>>c[i];
		if (p[c[i]])
			k1=p[c[i]],k2=i;
		p[c[i]]=i;
	}
	if (k1==0)
	{
		k1=p[1],k2=p[n-2];
		cout<<"AND "<<1<<" "<<k1<<endl;
		cout<<flush;int p1;cin>>p1;
		p1>>=1,p1<<=1;
		cout<<"AND "<<1<<" "<<k2<<endl;
		cout<<flush;int p2;cin>>p2;
		a[1]=p1+p2%2;
		for (int i=2;i<=n;i++)
			a[i]=a[1]^c[i];
	}
	else
	{
		cout<<"OR "<<k1<<" "<<k2<<endl;
		int l;cout<<flush;cin>>l;
		a[k1]=a[k2]=l;
		a[1]=c[k1]^l;
		for (int i=2;i<=n;i++)
			a[i]=a[1]^c[i];
	}
	cout<<"!";
	for (int i=1;i<=n;i++)cout<<" "<<a[i];
	return 0;
}