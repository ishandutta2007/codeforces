#include<cstdio>
const int maxn=100000;
int n,dep[maxn+10],a[maxn+10],ans=1;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		int x; scanf("%d",&x); a[dep[i]=dep[x]+1]^=1;
	}
	for(int i=1;i<=n;++i) ans+=a[i]; printf("%d",ans);
}