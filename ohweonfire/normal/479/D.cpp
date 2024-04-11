#include <cstdio>
#include <unordered_set>
using namespace std;
const int maxn=100005;
unordered_set<int> st;
int n,x,y,l,d[maxn],solvex,solvey;
int main()
{
	scanf("%d%d%d%d",&n,&l,&x,&y);
	solvex=solvey=false;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",d+i);
		st.insert(d[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(st.count(d[i]-x))
			solvex=true;
		if(st.count(d[i]-y))
			solvey=true;
	}
	if(solvex&&!solvey)
	{
		printf("1\n%d\n",y);
		return 0;
	}
	if(!solvex&&solvey)
	{
		printf("1\n%d\n",x);
		return 0;
	}
	if(solvex&&solvey)
	{
		puts("0");
		return 0;
	}
	if(x>y)swap(x,y);
	for(int i=1;i<=n;i++)
	{
		if(st.count(d[i]+x+y))
		{
			printf("1\n%d\n",d[i]+x);
			return 0;
		}
		if(d[i]>=x&&st.count(d[i]+y-x))
		{
			printf("1\n%d\n",d[i]-x);
			return 0;
		}
		if(d[i]+x<=l&&st.count(d[i]+x-y))
		{
			printf("1\n%d\n",d[i]+x);
			return 0;
		}
	}
	printf("2\n%d %d\n",x,y);
	return 0;
}