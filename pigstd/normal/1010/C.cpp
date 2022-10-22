#include<bits/stdc++.h>
using namespace std;

const int M=100010;
int a[M],ans[M],n,k;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int kk=a[1];
	for (int i=2;i<=n;i++)
		kk=gcd(kk,a[i]);
	kk=gcd(kk,k);
	cout<<k/kk<<endl;
	for (int i=0;i<k/kk;i++)
		cout<<i*kk<<' ';
	return 0;
}