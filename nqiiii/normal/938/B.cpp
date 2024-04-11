#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=0x3f3f3f3f,a[200000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	a[n+1]=1000000; a[0]=1;
	for(int i=0;i<=n;++i) ans=min(ans,max(a[i]-1,1000000-a[i+1]));
	printf("%d",ans);
}