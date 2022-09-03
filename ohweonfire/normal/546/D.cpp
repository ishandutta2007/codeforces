#include<bits/stdc++.h>
using namespace std;
const int maxn=5000005;
int t,a,b;
bool prime[maxn];
long long cnt[maxn];
void get(int &x)
{
	char c;
	for(c=getchar();c<'0'||c>'9';c=getchar());
	x=c-'0';
	for(c=getchar();c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
}
int main()
{
	for(int i=2;i<maxn;i++)prime[i]=true;
	for(int i=2;i<maxn;i++)
		if(prime[i])
		{
			for(int j=i+i;j<maxn;j+=i)
				prime[j]=false;
			long long prod=i;
			while(prod<maxn)
			{
				for(int j=prod;j<maxn;j+=prod)cnt[j]++;
				prod*=i;
			}
		}
	for(int i=1;i<maxn;i++)cnt[i]+=cnt[i-1];
	get(t);
	while(t--)
	{
		get(a);
		get(b);
		printf("%I64d\n",cnt[a]-cnt[b]);
	}
	return 0;
}