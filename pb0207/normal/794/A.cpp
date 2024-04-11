#include<cstdio>
#include<iostream>
using namespace std;

const int N=1e5+1e3+7;

int a,b,c,n,ans;

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d",&x);
		if(c>x&&x>b)
		ans++;
	}
	cout<<ans;
}