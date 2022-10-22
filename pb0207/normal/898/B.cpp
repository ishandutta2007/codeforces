#include<iostream>
#include<cstdio>
using namespace std;

int n,a,b;

int main()
{
	cin>>n>>a>>b;
	for(int i=0;i<=n/a;++i)
		if((n-i*a)%b==0)
		{
			printf("YES\n");
			cout<<i<<" "<<(n-i*a)/b;
			return 0;
		}
	printf("NO\n");
}