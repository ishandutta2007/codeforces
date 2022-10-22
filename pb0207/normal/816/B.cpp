#include<cstdio>
#include<iostream>
using namespace std;

const int N=3e5+1e3+7;

int n,k,q,l[N],r[N],u,v,has[N],ans[N];

int main()
{
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]),has[l[i]]+=1,has[r[i]+1]-=1;
	for(int i=1;i<=200000;i++)
		has[i]+=has[i-1];
	for(int i=1;i<=200000;i++)
		if(has[i]>=k)
			ans[i]=1;
	for(int i=1;i<=200000;i++)
		ans[i]+=ans[i-1];
	while(q--)
	{
		scanf("%d%d",&u,&v);
		cout<<ans[v]-ans[u-1]<<endl;
	}
}