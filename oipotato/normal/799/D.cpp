#include<bits/stdc++.h>
using namespace std;
struct numbers
{
	int num,ti;
}t[100010];
int c[100010],a,b,w,h,n,ans,tot;
bool cmp(int a,int b){return a>b;}
void dfs(long long h,long long w,int k,int tans)
{
	if(tans>=ans)return;
	if(h>=a&&w>=b)
	{
		ans=min(ans,tans);
		return;
	}
	if(k>tot)return;
	for(int i=t[k].ti;i>=0;i--)
	for(int j=t[k].ti-i;j>=0;j--)
	if(tans+i+j<=40)
	{
		long long th=h,tw=w;
		for(int p=1;p<=i;p++)
		if(th<a)th*=t[k].num;
		else break;
		for(int p=1;p<=j;p++)
		if(tw<b)tw*=t[k].num;
		else break;
		dfs(th,tw,k+1,tans+i+j);
	}
}
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
	if(c[i]!=c[i-1])
	{
		t[++tot].num=c[i];
		t[tot].ti=1;
	}
	else t[tot].ti++;
	for(int i=1;i<=tot;i++)t[i].ti=min(t[i].ti,40);
	ans=n+1;
	dfs(h,w,1,0);
	swap(a,b);
	dfs(h,w,1,0);
	if(ans==n+1)printf("-1");
	else printf("%d",ans);
	return 0;
}