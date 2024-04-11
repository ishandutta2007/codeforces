#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T;
int main(){
	scanf("%d",&T);
	while(T--){
		int n,K;
		scanf("%d%d",&n,&K);
		if(K==n-1){
			if(n==4)puts("-1");
			else{
				// 0,7 1,6 2,5 3,4
				// 0,1 7,6 2,5 3,4
				// 0,4 7,6 2,5 3,1
				vector<pair<int,int> >ans;
				rep(i,0,n-1)if(i<n-1-i)ans.eb(i,n-1-i);
				swap(ans[0].second,ans[1].first);
				swap(ans[0].second,ans.back().second);
				int s=0;
				rep(i,0,n/2-1){
					s+=ans[i].first&ans[i].second;
					printf("%d %d\n",ans[i].first,ans[i].second);
				}
				assert(s==K);
			}
		}else if(K==0){
			rep(i,0,n-1)if(i<n-1-i)printf("%d %d\n",i,n-1-i);
		}else{
			rep(i,0,n-1)if(i&&i!=K&&i!=n-1-K){
				if(i<n-1-i){
					printf("%d %d\n",i,n-1-i);
				}
			}
			printf("%d %d\n",0,n-1-K);
			printf("%d %d\n",n-1,K);
		}
	}
	return 0;
}