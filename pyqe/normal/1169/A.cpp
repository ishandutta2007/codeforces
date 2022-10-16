#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,a,x,b,y,i;
	
	scanf("%lld%lld%lld%lld%lld",&n,&a,&x,&b,&y);
	//cout<<a<<" "<<x<<" "<<b<<" "<<y<<endl;
	for(i=0;1;i++)
	{
		//cout<<(a+i-1)%n+1<<" "<<(b-i+n+n-1)%n+1<<endl;
		if((a+i-1)%n+1==(b-i+n+n-1)%n+1)
		{
			printf("YES\n");
			return 0;
		}
		if((a+i-1)%n+1==x||(b-i+n+n-1)%n+1==y)
		{
			break;
		}
	}
	printf("NO\n");
}