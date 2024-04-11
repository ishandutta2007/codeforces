#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,t,k,d,i;
	scanf("%d%d%d%d",&n,&t,&k,&d);
	int tot=0;
	int tot1=(n+k-1)/k*t;
	for(i=1;i;++i)
	{
		if(i%t==0)
		{
			tot+=k;
		}
		if((i-d)%t==0&&i-d>0)
		{
			tot+=k;
		}
		if(tot>=n)break;
	}
	if(tot1<=i)	cout<<"NO";
	else		cout<<"YES";
}