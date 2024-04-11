#include <bits/stdc++.h>
void work() {
	int n;
	scanf("%d", &n);
	std::vector<int> pos[2];
	for(int i=0; i<n; ++i) {
		int a;
		scanf("%d", &a);
		pos[a&1].push_back(i);
	}
	long long ans=-1;
	if(pos[0].size()==pos[1].size()+1) {
		ans=0;
		for(int i=0; i<(int)pos[0].size(); ++i) ans+=abs(pos[0][i]-2*i);
		for(int i=0; i<(int)pos[1].size(); ++i) ans+=abs(pos[1][i]-(2*i+1));
		ans/=2;
	}
	if(pos[0].size()==pos[1].size()-1) {
		ans=0;
		for(int i=0; i<(int)pos[0].size(); ++i) ans+=abs(pos[0][i]-(2*i+1));
		for(int i=0; i<(int)pos[1].size(); ++i) ans+=abs(pos[1][i]-2*i);
		ans/=2;
	}
	if(pos[0].size()==pos[1].size()) {
		long long ans1=0, ans2=0;
		for(int i=0; i<(int)pos[0].size(); ++i) ans1+=abs(pos[0][i]-2*i);
		for(int i=0; i<(int)pos[1].size(); ++i) ans1+=abs(pos[1][i]-(2*i+1));
		for(int i=0; i<(int)pos[0].size(); ++i) ans2+=abs(pos[0][i]-(2*i+1));
		for(int i=0; i<(int)pos[1].size(); ++i) ans2+=abs(pos[1][i]-2*i);
		ans=std::min(ans1, ans2)/2;
	}
	printf("%lld\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--)work();
	return 0;
}