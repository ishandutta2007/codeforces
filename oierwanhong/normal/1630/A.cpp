#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::vector<int> P;
typedef unsigned un;
ll read()
{
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
using std::min;
using std::max;
template<typename T>bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T>bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}

int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),k=read();
		if(k==n-1)
		{
			if(n==4){puts("-1");continue;}
			printf("1 3\n");
			printf("%d %d\n",n-1,n-2);
			printf("%d %d\n",2,n-3);
			printf("0 %d\n",n-4);
			for(int i=4;i<(n>>1);++i)printf("%d %d\n",i,(n-1)^i);
		}
		else if(k==0)
		{
			for(int i=0;i<(n>>1);++i)printf("%d %d\n",i,(n-1)^i);
		}
		else
		{
			printf("%d %d\n",k,n-1);
			printf("0 %d\n",(n-1)^k);
			for(int i=1;i<(n>>1);++i)
				if(i!=k&&i!=((n-1)^k))printf("%d %d\n",i,(n-1)^i);
		}
	}
	return 0;
}