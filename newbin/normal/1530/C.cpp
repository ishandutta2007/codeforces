#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
FILE*FP=freopen("text.in","r",stdin);
//FILE*fp=freopen("text.out","w",stdout);
#endif
#define N 100005
int t,n,my[N],she[N],l,r,ans;
bool jd(int sum){
	int cnt=sum-sum/4;
	if(cnt<=sum-n)return true;
	if(cnt<=n)return 100*(sum-n)+my[cnt-1-(sum-n)]>=she[cnt-1];
	return 100*(sum-n)+my[cnt-1-(sum-n)]>=she[n-1];
}
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",my+i);
		}
		for(int i=0;i<n;i++){
			scanf("%d",she+i);
		}
		sort(my,my+n,greater<int>());
		sort(she,she+n,greater<int>());
		for(int i=1;i<n;i++){
			my[i]+=my[i-1];
			she[i]+=she[i-1];
		}
		l=0;r=n;  
		while(l<r){
			ans=(l+r)/2;
			if(jd(ans+n))r=ans;
			else l=ans+1;
		}
		ans=(l+r)/2;
		printf("%d\n",ans);
	}
	return 0;
}