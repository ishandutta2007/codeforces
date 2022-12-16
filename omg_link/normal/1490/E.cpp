#include <stdio.h>
#include <algorithm>
#define MN 200000

int n,a[MN+5],b[MN+5];
long long pre[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	std::sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
		pre[i] = pre[i-1]+b[i];
	int lim = 0;
	for(int i=n;i>=1;i--){
		if(pre[i-1]<b[i]){
			lim = b[i];
			break;
		}
	}
	int ansc = 0;
	for(int i=1;i<=n;i++)
		if(a[i]>=lim) ansc++;
	printf("%d\n",ansc);
	for(int i=1;i<=n;i++)
		if(a[i]>=lim)
			printf("%d ",i);
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}