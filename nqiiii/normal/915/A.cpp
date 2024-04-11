#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,ans=0x3f3f3f3f;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		if(k%x==0) ans=min(ans,k/x);
	}
	printf("%d",ans); return 0;
}