#include <stdio.h>
#include <algorithm>
#include <vector>
typedef long long LL;

int n,c0;
std::vector<int> pos,neg;

void solve(){
	pos.clear(),neg.clear(),c0=0;
	scanf("%d",&n);
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		if(a>0) pos.push_back(a);
		if(a<0) neg.push_back(-a);
		if(a==0) c0++;
	}
	LL ans = -0x7fffffffffffffffll;
	std::sort(pos.begin(),pos.end(),std::greater<int>());
	std::sort(neg.begin(),neg.end(),std::greater<int>());
	if(pos.size()>=5){ //0 neg
		LL tans = 1;
		for(int i=0;i<5;i++)
			tans *= pos[i];
		ans = std::max(ans,tans);
	}
	if(pos.size()>=3&&neg.size()>=2){ // 2 neg
		LL tans = 1;
		for(int i=0;i<3;i++)
			tans *= pos[i];
		for(int i=0;i<2;i++)
			tans *= neg[i];
		ans = std::max(ans,tans);
	}
	if(pos.size()>=1&&neg.size()>=4){ // 4 neg
		LL tans = 1;
		for(int i=0;i<1;i++)
			tans *= pos[i];
		for(int i=0;i<4;i++)
			tans *= neg[i];
		ans = std::max(ans,tans);
	}
	std::sort(pos.begin(),pos.end(),std::less<int>());
	std::sort(neg.begin(),neg.end(),std::less<int>());
	if(neg.size()>=5){ // 5 neg
		LL tans = -1;
		for(int i=0;i<5;i++)
			tans *= neg[i];
		ans = std::max(ans,tans);
	}
	if(pos.size()>=2&&neg.size()>=3){ // 3 neg
		LL tans = -1;
		for(int i=0;i<2;i++)
			tans *= pos[i];
		for(int i=0;i<3;i++)
			tans *= neg[i];
		ans = std::max(ans,tans);
	}
	if(pos.size()>=4&&neg.size()>=1){ // 1 neg
		LL tans = -1;
		for(int i=0;i<4;i++)
			tans *= pos[i];
		for(int i=0;i<1;i++)
			tans *= neg[i];
		ans = std::max(ans,tans);
	}
	if(c0>0) ans = std::max(ans,0ll);
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}