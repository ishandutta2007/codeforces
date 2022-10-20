#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
int n,ans[N];
char buf[N];
string s,ss;
int main(){
	int t,i,j,cnt,k,l;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,&buf);
		ss=buf;
		s=">"+ss+"<";
		cnt=1;
		for(i=n;i>0;i=j)
		{
			k=i-1;
			for(j=i-1;j>=0;j--)
			{
				if(s[j]=='>'&&s[j+1]=='<')
				{
					break;
				}
				if(s[j]=='<'&&s[j+1]=='>')
				{
					k=j;
				}
			}
			if(j==-1)
			{
				for(l=i-1;l>=0;l--)
				{
					ans[l]=cnt++;
				}
			}
			else
			{
				for(l=i-1;l>k;l--)
				{
					ans[l]=cnt++;
				}
				for(l=j;l<=k;l++)
				{
					ans[l]=cnt++; 
				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
		cnt=1;
		for(i=-1;i<n-1;i=j)
		{
			k=i+1;
			for(j=i+1;j<n;j++)
			{
				if(s[j]=='>'&&s[j+1]=='<')
				{
					break;
				}
				if(s[j]=='<'&&s[j+1]=='>')
				{
					k=j;
				}
			}
			if(j==n)
			{
				for(l=i+1;l<n;l++)
				{
					ans[l]=cnt++;
				}
			}
			else
			{
				for(l=i+1;l<k;l++)
				{
					ans[l]=cnt++;
				}
				for(l=j;l>=k;l--)
				{
					ans[l]=cnt++; 
				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}