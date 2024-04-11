#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
char s[1000010],a[1000010],b[1000010];
int ans[30],n,k;
bool use[30];
queue<int>rest;
void print()
{
	for(;!rest.empty();rest.pop());
	rep(i,k)if(!use[i])rest.push(i);
	rep(i,k)if(!ans[i]){ans[i]=rest.front();rest.pop();}
	puts("YES");
	rep(i,k)putchar(ans[i]+'a'-1);puts("");
}
bool check(int now,bool t1,bool t2)
{
	if(now>n)
	{
		print();
		return 1;
	}
	int x=s[now]-'a'+1,l=t1?a[now]-'a'+1:1,r=t2?b[now]-'a'+1:k;
	if(ans[x])
	{
		if(ans[x]<l||ans[x]>r)return 0;
		if(ans[x]>l)t1=0;
		if(ans[x]<r)t2=0;
		return check(now+1,t1,t2);
	}
	if(l==r)
	{
		if(use[l])return 0;
		ans[x]=l;use[l]=1;
		bool flag=check(now+1,t1,t2);
		ans[x]=0;use[l]=0;
		return flag;
	}
	for(int i=l+1;i<r;i++)
	if(!use[i])
	{
		ans[x]=i;use[i]=1;
		bool flag=check(now+1,0,0);
		ans[x]=0;use[i]=0;
		if(flag)return 1;
	}
	if(!use[l])
	{
		ans[x]=l;use[l]=1;
		bool flag=check(now+1,t1,0);
		ans[x]=0;use[l]=0;
		if(flag)return 1;
	}
	if(!use[r])
	{
		ans[x]=r;use[r]=1;
		bool flag=check(now+1,0,t2);
		ans[x]=0;use[r]=0;
		if(flag)return 1;
	}
	return 0;
}
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&k);
		scanf("%s%s%s",s+1,a+1,b+1);
		n=strlen(s+1);
		rep(i,k)ans[i]=use[i]=0;
		if(!check(1,1,1))puts("NO");
	}
	return 0;
}