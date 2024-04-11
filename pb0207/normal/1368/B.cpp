#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

typedef long long ll;

ll n;

char s[]="codeforces";

int a[N];

int main()
{
	scanf("%lld",&n);
	ll tmp=pow(n,0.1);
	for(int i=0;i<10;i++)
		a[i]=tmp;
	ll val=1;
	for(int i=0;i<10;i++)
		val*=tmp;
	for(int i=0;i<10;i++)
	{
		if(val<n)
		{
			val/=a[i];
			a[i]++;
			val*=a[i];
		}
	}
	for(int i=0;i<10;i++)
		for(int j=0;j<a[i];j++)
			putchar(s[i]);
}