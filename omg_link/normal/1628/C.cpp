#include <stdio.h>
#include <string.h>
#define MN 1000

int n,a[MN+5][MN+5];
int cnt[MN+5][MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int ans = 0;
	memset(cnt,0,sizeof(cnt));
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((cnt[i-1][j]&1)==0){
				ans ^= a[i][j];
				cnt[i-1][j]++;
				cnt[i][j-1]++;
				cnt[i][j+1]++;
				cnt[i+1][j]++;
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}