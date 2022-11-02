#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
    	int x1,y1,z1,x2,y2,z2;
    	scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
    	int tmp=min(z1,y2);
    	z1-=tmp;
    	int ans=tmp*2;
    	tmp=min(z2,x1+z1);
    	z2-=tmp;ans-=2*z2;
    	printf("%d\n",ans);
    }
    return 0;
}