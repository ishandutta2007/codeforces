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
    	int n,k;
    	scanf("%d%d",&n,&k);
    	if(n>=k)printf("%d\n",(n-k)&1);
    	else printf("%d\n",k-n);
    }
    return 0;
}