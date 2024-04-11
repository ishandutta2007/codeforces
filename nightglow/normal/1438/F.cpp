#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<ctime>
#include<vector>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 100005

using namespace std;

int h,n,i,j,k,p,m,Max,Maxid,CMax,CMaxid;

map<int,int>mp;

int Rand()
{
		return (rand()<<15)+rand();
}

int main()
{
	srand((int)time(0));
	scanf("%d",&h); n=(1<<h)-1;
	for (i=1;i<=420;++i)
	{
			int x=Rand()%n+1,y=Rand()%n+1,z=Rand()%n+1;
			while (y==x) y=Rand()%n+1;
			while (z==x||z==y) z=Rand()%n+1;
			printf("? %d %d %d\n",x,y,z);
			fflush(stdout);
			scanf("%d",&x);
			mp[x]++; 
	}
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();++it)
	{
			int x=it->fi,y=it->se;
			if (y>Max) swap(Maxid,CMaxid),swap(Max,CMax),Maxid=x,Max=y;
			else if (y>CMax) CMaxid=x,CMax=y;
	}
	for (i=1;i<=n;++i)
		if (i!=CMaxid&&i!=Maxid) 
		{
				printf("? %d %d %d\n",CMaxid,Maxid,i);
				fflush(stdout);
				scanf("%d",&p);
				if (p==i)
				{
					printf("! %d\n",i);
					fflush(stdout); 		
					break;			 
				} 
		}
}