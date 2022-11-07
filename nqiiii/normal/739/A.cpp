#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,now=0x3f3f3f3f;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int l,r; scanf("%d%d",&l,&r); now=min(now,r-l+1);
	}
	printf("%d\n",now);
	for(int i=1;i<=n;++i) printf("%d ",i%now);
}