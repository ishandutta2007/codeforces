#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,ans[100001],cnt;

int chk(int x)
{
	if(x<0)
		return -1;
	int ret=0;
	while(x)
	{
		ret+=x%10;
		x/=10;
	}
	return ret;
}

int main()
{
	cin>>n;
	for(int i=1;i<=100;i++)
	{
		if(chk(n-i)==i)
			ans[++cnt]=n-i;
	}
	sort(ans+1,ans+cnt+1);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<ans[i]<<endl;
}