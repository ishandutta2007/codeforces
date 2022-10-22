#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int N=2e5+1e3+7;

char p[N],t[N];

int a[N],n,mk[N],m;

bool check(int val)
{
	memset(mk,0,sizeof(mk));
	for(int i=1;i<=val;i++)
		mk[a[i]]=1;
	int st=0,k=0;
	for(int i=0;i<n;i++)
		if(!mk[i])
		{
			if(t[i]==p[st])
			{
				k++;
				st++;
			}
			if(k>=m)
				return 1;
		}
	return 0;
}

int main()
{
	scanf("%s",t);
	scanf("%s",p);
	n=strlen(t);
	m=strlen(p);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]--;
	int l=0,r=n+1;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	printf("%d",l);
}