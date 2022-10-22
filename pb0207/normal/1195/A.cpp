#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,k,a[N],cnt[N];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	int lso=0,ans=0;
	for(int i=1;i<=k;i++)
	{
		if(cnt[i]&1)
		{
			if(lso)
				cnt[i]--;
			ans+=cnt[i],lso^=1;
		}
		else
			ans+=cnt[i];
	}
	printf("%d",ans);
}