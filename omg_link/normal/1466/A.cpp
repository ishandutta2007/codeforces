#include <stdio.h>
#include <string.h>
#define MN 50

int n,a[MN+5];
bool e[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans = 0;
	memset(e,0x00,sizeof(e));
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!e[a[j]-a[i]]){
				ans++;
				e[a[j]-a[i]] = true;
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}