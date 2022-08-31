#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,a,b,c,d;
inline int F(int x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a==c||b==d)
			printf("%d\n",F(a-c)+F(b-d));
		else
			printf("%d\n",F(a-c)+F(b-d)+2);
	}
	return 0;
}