#include<cstdio>
const int maxn=1500;
int n,m,a[maxn+10],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		for(int j=1;j<i;++j) if(a[i]<a[j]) ans^=1;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int l,r; scanf("%d%d",&l,&r);
		ans^=(r-l+1)/2%2;
		printf("%s\n",ans?"odd":"even");
	}
	return 0;
}