#include<cstdio>
using namespace std;
int n,cnt[1001],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		cnt[u]++;
		cnt[v]++;
	}
	for(int i=1;i<=n;i++)
		if(cnt[i]==1) ans++;
	printf("%d\n",ans);
}