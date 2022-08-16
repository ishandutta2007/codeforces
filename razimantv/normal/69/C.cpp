# include <algorithm>
# include <cctype>
# include <cmath>
# include <cstdio>
# include <cstring>
# include <iostream>
# include <set>
# include <vector>
# include <queue>

using namespace std;

char basic[50][101];
char composite[50][101];
char inp[100000];
char temp[101];
int cnt;
char composition[50][50];
char allycount[100][50];
char allytotal[100][50];

struct two
{
	const char *p;
	int cnt;
	bool operator<(const two t)const
	{
		return strcmp(p,t.p)<0;
	}
	two(const char *x,int c)
	{
		p=x;
		cnt=c;
	}
};

set<two> twoset;
set<two>::iterator iter;

int main()
{
	int K,N,M,Q;
	cin>>K>>N>>M>>Q;
	
	for(int i=0;i<N;i++)
		cin>>basic[i];
	
	cin.getline(inp,100000);
	for(int i=0;i<M;i++)
	{
		cin.getline(inp,100000);
		sscanf(inp,"%s",composite[i]);

		for(int j=0;composite[i][j];j++)
			if(composite[i][j]==':')
			{
				composite[i][j]=0;
				break;
			}
		char *ptr;
		ptr=inp;
		while(*ptr!=':')++ptr;
		while(1)
		{
			++ptr;
			sscanf(ptr,"%s %d",temp,&cnt);
			for(int j=0;j<N;j++)
				if(strcmp(temp,basic[j])==0)
				{
					composition[i][j]=cnt;
					break;
				}
			while(*ptr!=','&&*ptr!=0)++ptr;
			if(!(*ptr))break;
		}
	}
	
	for(int i=0;i<Q;i++)
	{
		int ally;
		cin>>ally>>temp;
		--ally;
		for(int j=0;j<N;j++)
			if(strcmp(basic[j],temp)==0)
			{
				allycount[ally][j]++;
				break;
			}
		bool flag=false;
		for(int j=0;j<M;j++)
		{
			if(flag)break;
			for(int k=0;k<N;k++)
				if(allycount[ally][k]<composition[j][k])
					goto bpp;
			flag=true;
			for(int k=0;k<N;k++)
				allycount[ally][k]-=composition[j][k];
			allytotal[ally][j]++;
			bpp:;
		}
	}
	
	for(int i=0;i<K;i++)
	{
		twoset.clear();
		for(int j=0;j<N;j++)
			if(allycount[i][j]>0)
				twoset.insert(two(basic[j],allycount[i][j]));
		for(int j=0;j<M;j++)
			if(allytotal[i][j]>0)
				twoset.insert(two(composite[j],allytotal[i][j]));
		printf("%d\n",twoset.size());
		for(iter=twoset.begin();iter!=twoset.end();iter++)
			printf("%s %d\n",iter->p,iter->cnt);
	}
	return 0;
}