#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<int,int> mp,mp2;
int n;
inline int getans(int x)
{
	if(!x) return 0;
	//printf("%d\n",x);
	if(mp2.count(x)) return mp2[x];
	int vis=0;
	for(int i=1;i<=30;i++)
	{
		if((x>>(i-1))==0) break;
		int nw=(1<<(i-1))-1;
		int q=getans((x>>i)|(x&nw));
		//printf("q=%d\n",q);
		vis|=1<<q;
	}
	//printf("vis=%d\n",vis);
	for(int i=0;i<=30;i++)
		if(!(vis&(1<<i)))
			return mp2[x]=i;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		for(int j=2;j*j<=x;j++)
			if(x%j==0)
			{
				int ct=0;
				while(x%j==0) x/=j,ct++;
				mp[j]|=1<<(ct-1);
			}
		if(x!=1) mp[x]|=1;
	}
	int tans=0;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		int nw=it->second;
		//printf("nw=%d\n",nw);
		tans^=getans(nw);
	}
	if(tans==0) printf("Arpa");
	else printf("Mojtaba");
	return 0;
}