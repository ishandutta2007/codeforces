#include<cstdio>
#include<string>
using namespace std;
int que[10000000];
char ss[10000000];
int day[13]={0,31,60,91,121,152,182,213,244,274,305,335,366};
int main()
{
	int n,m;
	int head=0,tail=0;
	int now;
	int ye,mo,da,h,mi,s;
	scanf("%d%d",&n,&m);
	while(scanf("%d-%d-%d %d:%d:%d:",&ye,&mo,&da,&h,&mi,&s)!=EOF)
	{
		gets(ss);
		now=day[mo-1];
		now=(now+da-1)*24*60*60+h*60*60+mi*60+s;
		que[tail++]=now;
		while(que[head]<=now-n)head++;
		if(tail-head>=m){printf("2012-%02d-%02d %02d:%02d:%02d\n",mo,da,h,mi,s);return 0;}
	}
	printf("-1\n");
}