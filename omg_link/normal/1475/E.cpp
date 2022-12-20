#include <stdio.h>
#include <algorithm>
#define MN 1000
const int mod = 1000000007;

int n,k,a[MN+5];
int C[MN+5][MN+5];

void init(int n){
	C[0][0] = 1;
	for(int i=1;i<=n;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++)
			C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
	}
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a+1,a+1+n,std::greater<int>());
	int l = k;
	int r = k;
	while(a[l-1]==a[k]&&l-1>=1) l--;
	while(a[r+1]==a[k]&&r+1<=n) r++;
	printf("%d\n",C[r-l+1][k-l+1]);
}

int main(){
	init(MN);
	int T; scanf("%d",&T);
	while(T--) solve();
}