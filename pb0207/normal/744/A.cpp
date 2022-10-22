#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>mp;
int pre[1100],ran[1100];
int find(int x)
{
	if(x==pre[x])
	return x;
	return pre[x]=find(pre[x]);
} 
void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	{
		pre[fx]=fy;
		ran[fy]+=ran[fx];
	}
}
int n,m,k,i,j,a,b,c[1100],gov[1100];
int main()
{
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		for(i = 0; i <= n; i++)
		{
			pre[i] = i;
			ran[i] = 1;
			gov[i]=0;
		}
		for(i=0;i<k;i++)
		{
			scanf("%d",&c[i]);
		}
		for(i = 0; i < m; i++)
		{
			scanf("%d%d",&a,&b);
			merge(a,b);
		}
		for(i = 0; i < k; i++)
		{
			gov[find(c[i])]=1;// 
		}
		int sum = 0,maxx = 0;
		for(i = 1; i <= n; i++)
		{
			if(find(i)==i)
			{
				if(gov[i])// 
				{
					maxx = max(ran[i] , maxx);
				}
				else
				{
					mp.push_back(ran[i]);
				}
				sum += ran[i]*(ran[i]-1)/2;// 
			}
		}
		for(i = 0; i < mp.size(); i++)
		{
			for(j = i+1; j<mp.size(); j++)
			{
				sum +=mp[i]*mp[j];// 
			 } 
			 sum+=mp[i]*maxx;// 
		}
		printf("%d\n",sum-m);//m 
	}
	return 0;
}