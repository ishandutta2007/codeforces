#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
int k, n, ax[7], ay[7], mx[1000], my[1000], prev[7][1000], len[7][1000];
char shooted[7], aimed[1000];
std::vector<int> obj;
std::pair<std::pair<int, int>, std::pair<int, int>> diff[1000];

int gcd(int x, int y) {return y?gcd(y, x%y):x;}
bool aim() {
	if(obj.empty()) return true;
	int cur=obj.back();
	obj.pop_back();
	for(int i=0; i<k; ++i) {
		if(shooted[i]||len[i][cur]>k) continue;
		shooted[i]=1;
		for(int j=cur; j!=-1; j=prev[i][j]) if(++aimed[j]==1) obj.push_back(j);
		if(obj.size()<=k&&aim()) return true;
		shooted[i]=0;
		for(int j=cur; j!=-1; j=prev[i][j]) if(--aimed[j]==0) obj.pop_back();
	}
	obj.push_back(cur);
	return false;
}
int main() {
	assert(scanf("%d%d", &k, &n)==2);
	for(int i=0; i<k; ++i) assert(scanf("%d%d", ax+i, ay+i)==2);
	for(int i=0; i<n; ++i) assert(scanf("%d%d", mx+i, my+i)==2);
	for(int i=0; i<k; ++i) {
		for(int j=0; j<n; ++j) {
			int x=mx[j]-ax[i], y=my[j]-ay[i], d=gcd(abs(x), abs(y));
			diff[j]=std::make_pair(std::make_pair(x/d, y/d), std::make_pair(d, j));
		}
		std::sort(diff, diff+n);
		for(int j=0; j<n; ++j) {
			int cur=diff[j].second.second;
			if(j>0 && diff[j].first==diff[j-1].first) {
				int las=diff[j-1].second.second;
				prev[i][cur]=las;
				len[i][cur]=len[i][las]+1;
			} else {
				prev[i][cur]=-1;
				len[i][cur]=1;
			}
		}
	}
	int ans=0;
	for(int i=0; i<n; ++i) {
		memset(shooted, 0, k);
		memset(aimed, 0, n);
		aimed[i]=1;
		obj={i};
		ans+=aim();
	}
	printf("%d\n", ans);
	return 0;
}