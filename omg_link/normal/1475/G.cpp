#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 200000

int n,a[MN+5],f[MN+5],lst[MN+5];

void solve(){
	memset(lst,0,sizeof(lst));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	int ans = 0x3fffffff;
	for(int i=1;i<=n;i++){
		f[i] = 0x3fffffff;
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				f[i] = std::min(f[i],f[lst[j]]+i-lst[j]-1);
				f[i] = std::min(f[i],f[lst[a[i]/j]]+i-lst[a[i]/j]-1);
			}
		}
		lst[a[i]] = i;
		ans = std::min(ans,f[i]+n-i);
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}