#include<iostream>
#include<cstdio>
typedef long long ll;
struct stk//stack
{
	ll a[1000001],t;
	void start(){t=0;}
	void push(ll x)
	{
		a[++t]=x;
	}
	ll top()
	{
		return a[t];
	}
	ll pop()
	{
		return a[t--];
	}
	bool empty(){return t==0;}
};
stk s;
char a[1000001];
ll len=0,ans=0;
int main()
{
	char k;
	while(1)
	{
		k=getchar();
		if(k=='\n'||k=='\r')break;
		a[++len]=k;
	}
	for(ll i=1;i<=len;++i)
	{
		if(s.empty()||s.top()!=a[i])s.push(a[i]);
		else ++ans,s.pop();
	}
	printf("%s",ans&1?"Yes":"No");
	return 0;
}