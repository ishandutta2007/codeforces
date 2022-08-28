#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ct0,ct1,ct2,ct3,sx,sy;
int main()
{
	scanf("%d%d%d",&n,&sx,&sy);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<sx) ct3++;
		if(x>sx) ct1++;
		if(y<sy) ct2++;
		if(y>sy) ct0++;
	}
	int nw=max(max(ct0,ct3),max(ct1,ct2));
	printf("%d\n",nw);
	if(nw==ct0)
		printf("%d %d",sx,sy+1);
	else if(nw==ct1)
		printf("%d %d",sx+1,sy);
	else if(nw==ct2)
		printf("%d %d",sx,sy-1);
	else if(nw==ct3)
		printf("%d %d",sx-1,sy);
	return 0;
}