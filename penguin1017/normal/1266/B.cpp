#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=1e5+9;
int dp[N],a[8]={3,4,5,6,8,9,10,11};
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll n;
		scanf("%lld",&n);
		if(n<=14){
			printf("NO\n");
			continue;
		}
		int last=n%14;
		if(last>0&&last<7){
			printf("YES\n");
		}
		else printf("NO\n");
	}
}