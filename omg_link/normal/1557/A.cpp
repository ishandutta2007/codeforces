#include <stdio.h>
#include <algorithm>
#define MN 100000

using std::max;

void solve(){
	int n;
	scanf("%d",&n);
	double sum = 0;
	double mx = -1e100;
	for(int i=1;i<=n;i++){
		double a;
		scanf("%lf",&a);
		sum += a;
		mx = max(mx,a);
	}
	printf("%.8f\n",(sum-mx)/(n-1)+mx);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}