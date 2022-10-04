#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,ludu[1005],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1,a,b;i<n;i++) scanf("%d%d",&a,&b),ludu[a]++,ludu[b]++;
	for(int i=1;i<=n;i++) if(ludu[i]==1) ans++;
	printf("%d",ans);
	return 0;
}