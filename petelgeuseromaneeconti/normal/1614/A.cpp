#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int n,l,r,K;
		scanf("%d%d%d%d",&n,&l,&r,&K);
		vector<int>a(n),b;
		rep(i,0,n-1){
			scanf("%d",&a[i]);
			if(a[i]>=l&&a[i]<=r){
				b.push_back(a[i]);
			}
		}
		sort(b.begin(),b.end());
		int ans=0;
		for(auto&x:b){
			if(K>=x){
				K-=x;
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}