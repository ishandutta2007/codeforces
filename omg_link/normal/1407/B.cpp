#include <stdio.h>
#include <algorithm>
#define MN 1000

int n,a[MN+5];
bool usd[MN+5];

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		usd[i] = false;
	}
	std::sort(a+1,a+1+n,std::greater<int>());
	int g = a[1];
	printf("%d ",a[1]);
	usd[1] = true;
	for(int i=2;i<=n;i++){
		int id=-1,mg=0;
		for(int j=1;j<=n;j++){
			if(usd[j]) continue;
			if(gcd(g,a[j])>mg){
				mg = gcd(g,a[j]);
				id = j;
			}
		}
		g = mg;
		printf("%d ",a[id]);
		usd[id] = true;
	}
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}