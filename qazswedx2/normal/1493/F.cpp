#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,fl;
int query(int len,int a,int b)
{
	if(!fl) printf("? %d %d %d %d %d %d\n",len,m,a,1,b,1);
	else printf("? %d %d %d %d %d %d\n",n,len,1,a,1,b);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int a[100005],at,b[100005];
bool check(int x,int l)
{
	if(l==2) return query(x/2,1,x/2+1);
	int nw=x/l*(l/2);
	return query(nw,1,nw+1)&&query(nw,1,nw+x/l+1);
}
int solve(int x)
{
	at=0;
	int nw=x;
	for(int i=2;i<=nw;i++)
		if(nw%i==0)
		{
			a[++at]=i;
			b[at]=0;
			while(nw%i==0) b[at]++,nw/=i;
		}
	int ans=1;
	for(int i=1;i<=at;i++)
	{
		for(int j=1;j<=b[i];j++)
		{
			if(check(x/ans,a[i]))
				ans*=a[i];
			else break;
		}
	}
	return ans;
}
int getans(int x)
{
	int ans=0;
	for(int i=1;i<=x;i++)
		if(x%i==0) ans++;
	return ans;
}
int main()
{
	int ans1,ans2;
	scanf("%d%d",&n,&m);
	ans1=solve(n);
	fl=1;
	ans2=solve(m);
	printf("! %d\n",getans(ans1)*getans(ans2));
	return 0;
}