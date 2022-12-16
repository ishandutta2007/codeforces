#include <stdio.h>
#include <algorithm>
#define MN 200000

using std::min;

const int INF = 0x3fffffff;

int n;
int cnt[MN+5];
int pre[MN+5];

int toFilled(int x){
	int r = 1;
	while(r<x){
		r <<= 1;
	}
	return r;
}

int bins(int v){
	int l = 1;
	int r = n;
	while(l<=r){
		int mid = (l+r)>>1;
		if(pre[mid]<=v)
			l = mid+1;
		else
			r = mid-1;
	}
	return r;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cnt[i] = 0;
	}
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	for(int i=1;i<=n;i++){
		pre[i] = pre[i-1]+cnt[i];
	}
	int ans = INF;
	for(int i=1;i<=n;i++){
		int p1 = toFilled(pre[i]);
		for(int p2=1;p2<=n;p2<<=1){
			int rpos = bins(pre[i]+p2);
			int p3 = toFilled(pre[n]-pre[rpos]);
			ans = min(ans,p1+p2+p3-n);
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}