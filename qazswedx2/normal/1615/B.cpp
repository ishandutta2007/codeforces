#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,l,r;
int check(int x,int v)
{
	int u=(x>>(v+1))<<(v+1);
	int uu=x-u;
//	printf("check:x=%d,v=%d,%d,%d\n",x,v,u/2,max(0,uu-v+1));
	return u/2+max(0,uu-(1<<v)+1);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&l,&r);
		int ans=0;
		for(int i=0;i<20;i++)
		{
			ans=max(ans,check(r,i)-check(l-1,i));
		}
		ans=r-l+1-ans;
		printf("%d\n",ans);
	}
	return 0;
}