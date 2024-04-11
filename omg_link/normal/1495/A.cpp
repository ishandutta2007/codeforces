#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

void solve(){
	int n;
	std::vector<int> a,b;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==0){
			a.push_back(std::abs(y));
		}else{
			b.push_back(std::abs(x));
		}
	}
	std::sort(a.begin(),a.end());
	std::sort(b.begin(),b.end());
	double ans = 0;
	for(int i=0;i<n;i++){
		ans += sqrt(1ll*a[i]*a[i]+1ll*b[i]*b[i]);
	}
	printf("%.15lf\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}