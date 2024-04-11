#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int x,y;
};
void getmov(pt &a,char ch)
{
	if(ch=='L') a.x--;
	if(ch=='R') a.x++;
	if(ch=='U') a.y++;
	if(ch=='D') a.y--;
}
int t,n;
char s[100005];
bool check(pt a)
{
	pt u;
	u.x=u.y=0;
	for(int i=1;i<=n;i++)
	{
		pt v=u;
		getmov(v,s[i]);
		if(v.x!=a.x||v.y!=a.y) u=v;
	}
	return u.x==0&&u.y==0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		pt u;
		u.x=u.y=0;
		int fl=0;
		for(int i=1;i<=n;i++)
		{
			getmov(u,s[i]);
			if(check(u))
			{
				fl=1;
				printf("%d %d\n",u.x,u.y);
				break;
			}
		}
		if(!fl) printf("0 0\n");
	}
	return 0;
}