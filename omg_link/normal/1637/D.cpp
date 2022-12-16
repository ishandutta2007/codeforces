#include <stdio.h>
#include <bitset>
#define MN 100
#define MA 100

using B = std::bitset<MN*MA+5>;

int n,a[MN+5],b[MN+5];
B f[MN+5];

void solve(){
	scanf("%d",&n);
	int sum = 0;
	int ans = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
		ans += (n-2)*a[i]*a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		sum += b[i];
		ans += (n-2)*b[i]*b[i];
	}
	f[0][0] = 1;
	for(int i=1;i<=n;i++){
		f[i] = (f[i-1]<<a[i])|(f[i-1]<<b[i]);
	}
	for(int i=sum/2;i>=0;i--){
		if(f[n][i]){
			int sumA = i;
			int sumB = sum-sumA;
			ans += sumA*sumA+sumB*sumB;
			printf("%d\n",ans);
			return;
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}