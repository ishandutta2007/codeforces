#include<iostream>
#include<cstdio>
typedef long long ll;
const ll maxn=1e9;
ll t[10001],ans[200001],o[200001];
ll n,k,size=0,len=0;
void start()
{
	std::cin>>n>>k;
	for(ll p=1;p<=n;p<<=1)t[++size]=p;
}
void check()
{
	while(size>0)
	{
		while(size>0&&t[size]>n)--size;
		if(size==0)break;
		o[++len]=t[size];
		n-=t[size];
	}
}
void end()
{
	if(len>k)std::cout<<"NO";
	else
	{
		for(ll i=1;i<=len;++i)
		{
			while(o[i]>1&&len<k)o[++len]=(o[i]>>=1);
		}
		if(len>k||len<k)std::cout<<"NO";
		else
		{
			std::cout<<"YES\n";
			while(len>0)std::cout<<o[len--]<<" ";
		}
	}
}
int main()
{
	start();
	check();
	end();
	return 0;
}