#include<cstdio>
#include<cstring>

int x,y,z,t1,t2,t3;

int getabs(int a) {return a<0?-a:a;}

int main()
{
	scanf("%d%d%d%d%d%d",&x,&y,&z,&t1,&t2,&t3);
	int ans1=getabs(y-x)*t1,ans2=0;
	ans2=getabs(z-x)*t2+t3;
	ans2+=2*t3+getabs(y-x)*t2;
	if (ans2<=ans1) printf("YES\n"); else printf("NO\n");
	return 0;
}