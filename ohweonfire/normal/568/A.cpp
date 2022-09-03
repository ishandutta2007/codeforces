#include<bits/stdc++.h>
using namespace std;
const int maxn=3000005;
int palin[maxn],prime[maxn],p,q;
bool pr[maxn];
void process()
{
	for(int i=2; i<maxn; i++)pr[i]=true;
	for(int i=2; i<maxn; i++)
	{
		prime[i]=prime[i-1];
		if(pr[i])
		{
			prime[i]++;
			for(int j=i+i;j<maxn;j+=i)pr[j]=false;
		}
	}
}
int digit[10];
bool check(int x)
{
	int cnt=0;
	while(x!=0)
	{
		digit[cnt++]=x%10;
		x/=10;
	}
	for(int i=0;i<(cnt>>1);i++)if(digit[i]!=digit[cnt-i-1])return false;
	return true;
}
int main()
{
	scanf("%d%d",&p,&q);
	process();
	for(int i=1;i<maxn;i++)
	{
		palin[i]=palin[i-1];
		if(check(i))palin[i]++;
	}
	int ans=-1;
	for(int i=1;i<maxn;i++)
		if(q*1ll*prime[i]<=p*1ll*palin[i])ans=i;
	if(ans==-1)puts("Palindromic tree is better than splay tree");
	else printf("%d\n",ans);
	return 0;
}