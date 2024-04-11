#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tt,n,m,t;
char a[100005],ans[100005];
int F(int x)
{
	if(x=='a'||x=='a'+m-1) return 'a';
	return x-1;
}
void solve(int x,char c)
{
//	ans[t+1]=0;
//	printf("solve:x=%d,c=%c,ans=%s\n",x,c,ans+1);
	if(x>n)
	{
		if(c) ans[++t]=c;
		return;
	}
	if(!c)
	{
		int q1=F(a[x]),q2=F(a[x+1]),q3=a[x+2],mn;
		if(x+1>n) q2=1e9;
		if(x+2>n) q3=1e9;
		mn=min(min(q1,q2),q3);
		if(q1==mn)
		{
			ans[++t]=q1;
			solve(x+1,0);
		}
		else if(q2==mn)
		{
			ans[++t]=q2;
			solve(x+2,a[x+1]=='a'?F(a[x]):a[x]);
		}
		else
		{
			ans[++t]=q3;
			ans[++t]=q1;
			solve(x+3,a[x+1]);
		}
	}
	else
	{
		int q1=c,q2=a[x],q3=a[x+1],mn;
		if(x+1>n) q3=1e9;
		mn=min(min(q1,q2),q3);
		if(q1==mn)
		{
			ans[++t]=q1;
			solve(x,0);
		}
		else if(q2==mn)
		{
			ans[++t]=q2;
			solve(x+1,c);
		}
		else
		{
			ans[++t]=q3;
			ans[++t]=q1;
			solve(x+2,q2);
		}
	}
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d%s",&n,&m,a+1);
		t=0;
		solve(1,0);
		ans[t+1]=0;
		printf("%s\n",ans+1);
	}
	return 0;
}