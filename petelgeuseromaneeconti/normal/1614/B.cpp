#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		vector<pair<int,int> >a(n);
		rep(i,0,n-1)scanf("%d",&a[i].first),a[i].second=i;
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		vector<int>ans(n);
		int l=0,r=0;
		LL sum=0;
		rep(i,0,n-1){
			ans[a[i].second]=i&1?--l:++r;
			sum+=abs(ans[a[i].second])*2LL*a[i].first;
		}
		printf("%lld\n",sum);
		printf("0 ");
		rep(i,0,n-1)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}