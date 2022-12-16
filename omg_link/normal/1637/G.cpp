#include <stdio.h>
#include <map>
#include <vector>

using std::map;
using std::vector;

using pii = std::pair<int,int>;

map<int,int> cnt;
vector<pii> opt;

bool isEDCM(int n){
	return __builtin_popcount(n)==1;
}

int getTarget(int n){
	int ret = 1;
	while(ret<n) ret <<= 1;
	return ret;
}

void solve(int base,int n){
	while(isEDCM(n)){
		cnt[base*n] += 1;
		n--;
	}
	if(n==0) return;
	int target = getTarget(n);
	int len = n-target/2;
	cnt[base*target] += len;
	cnt[base*target/2] += 1;
	for(int i=1;i<=len;i++){
		opt.push_back({base*(target/2-i),base*(target/2+i)});
	}
	solve(base*2,len);
	solve(base,target/2-len-1);
}

void toDouble(int x){
	opt.push_back({0,x});
	opt.push_back({x,x});
	cnt[x*2]++;
}

void solve(){
	int n;
	scanf("%d",&n);
	if(n==2){
		puts("-1");
		return;
	}
	solve(1,n);
	int target = getTarget(n);
	int ctar = -1;
	for(auto& p:cnt){
		if(p.second>=2){
			ctar = p.first;
			break;
		}
	}
	cnt[ctar] -= 2;
	cnt[2*ctar] += 1;
	opt.push_back({ctar,ctar});
	for(int i=1;i<target;i<<=1){
		for(int j=0;j<cnt[i];j++){
			toDouble(i);
		}
	}
	opt.push_back({0,target});
	printf("%d\n",(int)opt.size());
	for(auto p:opt){
		printf("%d %d\n",p.first,p.second);
	}
	cnt.clear();
	opt.clear();
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}