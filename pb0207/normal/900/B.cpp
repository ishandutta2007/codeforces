#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

ll a,b;

int c;

int main()
{
	cin>>a>>b>>c;
	a%=b;
	for(int i=1;i<=100000;i++)
	{
		a*=10;
		ll k=a/b;
		if(k==c)
		{
			printf("%d",i);
			return 0; 
		}
		a-=b*k;
	}
	puts("-1");
}