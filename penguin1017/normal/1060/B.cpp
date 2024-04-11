#include<iostream>
using namespace std;
int main()
{
	long long pos=0,n1,n,ans,sum=0;
	cin>>n;
	int i=0;
	n1=n;
	while(n1)
	{
		n1/=10;
		pos++;
	}
	ans=9*(pos-1);
	for(i=pos-1;i;i--)
	{
		sum=sum*10+9;
	}
	n-=sum;
	while(n)
	{
		ans+=n%10;
		n/=10;
	}
	cout<<ans;
}