#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a1,a2,a3,b1,b2,b3;
void upd(int &x,int &y)
{
	if(x>=y) x-=y,y=0;
	else y-=x,x=0;
}
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3);
	int ans1=min(a1,b2)+min(a2,b3)+min(a3,b1),ans2;
	int fl=0;
	if(a1<=b1+b3) fl=min(min(b1+b3-a1,b1),a1);
	upd(a1,b1);
	upd(a1,b3);
	upd(a2,b1);
	upd(a2,b2);
	if(a2>0)
	{
		int g=min(a2,fl);
		a2-=g;
		b3-=g;
	}
	upd(a3,b2);
	upd(a3,b3);
	ans2=a1+a2+a3;
	printf("%d %d\n",ans2,ans1);
}