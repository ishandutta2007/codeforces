#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int raw[200010];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++)scanf("%d",&raw[i]);
	sort(&raw[1],&raw[n+1]);
	int mid = (n+1)/2;
	ll ans = 0;
	for(int i = mid;i >= 1;i--){
		if(raw[i] > k)ans += raw[i] - k;
//		else break;
	}
	for(int i = mid;i <= n;i++){
		if(raw[i] < k)ans += k - raw[i];
//		else break;
	}
	printf("%lld",ans);
	
}