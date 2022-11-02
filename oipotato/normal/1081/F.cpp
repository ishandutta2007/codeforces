#include<cstdio>
#include<cassert>
#include<ctime>
using namespace std;
int a[310],now[310],n,T,t;
int ans[310],p[310];
int get(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int x;scanf("%d",&x);
	return x;
/*	int fuck=rand()&1;
	if(fuck)for(int i=l;i<=n;i++)p[i]^=1;else for(int i=1;i<=r;i++)p[i]^=1;
	int x=0;
	for(int i=1;i<=n;i++)x+=p[i];
	return x;*/
}
int main()
{
//	srand(time(0));
//	for(;;){
	scanf("%d%d",&n,&t);
//	n=4;t=0;
//	for(int i=1;i<=n;i++)ans[i]=rand()&1,p[i]=ans[i],t+=ans[i];
	int init=t;
	if(n==1)
	{
		printf("! %d\n",t);
		fflush(stdout);
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int x;
		bool flag=0;
		for(int j=1;j<=30;j++)
		{
			T++;
			x=get(i+1,n);
			for(int j=1;j<i;j++)now[j]^=1;
			if(n-t==x){t=x;continue;}
			t=n-t;
			for(int j=1;j<i;j++)t-=now[j];
			for(int j=1;j<i;j++)t+=(now[j]^=1);
			assert(t!=x);
			if(t>x)now[i]=0;else now[i]=1;
			a[i]=now[i]^(T&1)^1;
			flag=1;
			t=x;
			break;
		}
		if(!flag)
		{
			int num=0;
			for(int j=1;j<i;j++)num+=now[j];
			if(num==i/2)now[i]=0;else now[i]=1;
			a[i]=now[i]^(T&1);
		}
	}
	for(int i=1;i<n;i++)init-=a[i];a[n]=init;
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d",a[i]);puts("");
	fflush(stdout);
//	for(int i=1;i<=n;i++)if(a[i]!=ans[i]){puts("fuck");for(int j=1;j<=n;j++)printf("%d",ans[j]);puts("");for(int j=1;j<=n;j++)printf("%d",a[j]);puts("");return 0;}
//		puts("OK");
//	}
	return 0;
}