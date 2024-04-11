#include<cstdio>
#include<iostream>
using namespace std;
int T,x,y,p,q,k;
long long ans;
int main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d%d",&x,&y,&p,&q);
		if(x==y&&p==q)ans=0;
		else if(p==q)ans=-1;
		else if(x==0&&p==0)ans=0;
		else if(p==0)ans=-1;
		else
		{
			k=max((y-x)/(q-p)+((y-x)%(q-p)!=0),max(y/q+(y%q!=0),x/p+(x%p!=0)));
			ans=(long long)q*k-y;
		}
		cout<<ans<<endl;
	}
	return 0;
}