#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int M=1e6+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
int is[M];
vector<int>a[N];
void ysgs(int n)
{
	memset(is,1,sizeof(is));
	for (int i=2;i<=n;i++)
	for (int j=i+i;j<=n;j+=i) is[j]=0;
}
void GreenDay()
{
	ll ans=0;
	int n=read(),k=read();
	for (int i=0;i<k;i++) a[i].clear();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (x==1) a[i%k].push_back(0);
		else if (is[x]) a[i%k].push_back(1);
		else a[i%k].push_back(2);
	}
	for (int t=0;t<k;t++)
	{
		auto &b=a[t];
		int n=b.size();
		for (int i=0,j=0,sum=0;i<n;i++)
		{
			sum+=b[i];
			while (sum>1) sum-=b[j++];
			ans+=max(i-j,0);
		}
		for (int i=0,j=0,sum=0;i<n;i++)
		{
			sum+=b[i];
			while (sum>0) sum-=b[j++];
			ans-=max(i-j,0);
		}
	}
	print(ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	ysgs(1e6);
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}