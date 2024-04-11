#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

ll get1(ll *x)
{
	ll a=x[1],b=x[2],c=x[3];
	if (a>b) swap(a,b);
	if (b>c) swap(b,c);
	if (a>b) swap(a,b);
	return c+c-a-b;
}
ll get2(ll *x)
{
	ll a=x[1],b=x[2],c=x[3];
	if (a>b) swap(a,b);
	if (b>c) swap(b,c);
	if (a>b) swap(a,b);
	return c-b;
}

signed main()
{
	ll a[4]={},k;
	for (int i=1;i<=3;i++) a[i]=read();
	cout<<"First\n"<<(k=get1(a))<<endl;
	a[read()]+=k;
	if (a[0]) return 0;
	cout<<(k=get1(a))<<endl;
	a[read()]+=k;
	if (a[0]) return 0;
	cout<<get2(a)<<endl;
	
	return 0;
}