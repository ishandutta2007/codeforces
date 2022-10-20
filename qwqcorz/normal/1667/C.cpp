#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void Set(int x,int y){print(x,' '),print(y);}

signed main()
{
	int n=read(),m=n*2-1,r=m%3;
	if (r==1) r+=3;
	int k=(m-r)/3;
	if (n==1) return puts("1\n1 1"),0;
	print(k+r/2);
	for (int i=0;i<r/2;i++) Set(n,n),n--;
	for (int i=1;i<=k;i+=2) Set(i,k/2+i/2+1);
	for (int i=2;i<=k;i+=2) Set(i,i/2);
	
	return 0;
}