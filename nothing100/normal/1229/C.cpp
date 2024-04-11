#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,sma[100010],q;
LL ans;
vector<int> big[100010]; 
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		int o,p;
		scanf("%d%d",&o,&p);
		if (o>p) swap(o,p);
		big[o].push_back(p);
		sma[p]++;
	}
	for (int i=1;i<=n;i++){
		ans=ans+1ll*sma[i]*big[i].size();
	}
	printf("%lld\n",ans);
	
	scanf("%d",&q);
	while (q--){
		int o;
		scanf("%d",&o);
		ans-=1ll*sma[o]*big[o].size();
		//printf("gg\n");
		for (int i=0;i<big[o].size();i++){
			//printf("%d\n",big[o][i]);
			ans-=big[big[o][i]].size();
			sma[big[o][i]]--;
			ans+=sma[big[o][i]];
			big[big[o][i]].push_back(o);
			sma[o]++;
		}
		big[o].clear();
		printf("%lld\n",ans);
	}
}