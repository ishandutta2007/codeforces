#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int a[100010],b[100010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
    	int n;
    	scanf("%d",&n);
    	rep(i,n)scanf("%d",&a[i]),b[i]=a[i];
    	sort(b+1,b+n+1);
    	bool flag=1;
    	rep(i,n)if(a[i]!=b[i]&&a[i]%b[1]){flag=0;break;}
    	puts(flag?"YES":"NO");
    }
    return 0;
}