#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100000;
int n,a[maxn+10],minv=2e9,ans=2e9,pre=-2e9;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		minv=min(minv,a[i]);
	}
	for(int i=1;i<=n;++i)
		if(a[i]==minv){
			ans=min(ans,i-pre); pre=i;
		}
	printf("%d",ans); return 0;
}