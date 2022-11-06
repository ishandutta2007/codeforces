#include<cstdio>
#include<algorithm>
using namespace std;
int n,a,b,ans;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<n;++i) ans=max(ans,min(a/i,b/(n-i)));
	printf("%d",ans);
}