#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using std::abs;
using std::min,std::max;
using std::greater;
using std::vector;
using std::priority_queue;

int n,m;

int maxDist(int x,int y){
	return max(abs(x-1),abs(x-n))+max(abs(y-1),abs(y-m));
}

void solve(){
	scanf("%d%d",&n,&m);
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			pq.push(maxDist(i,j));
	while(!pq.empty()){
		int x = pq.top();
		pq.pop();
		printf("%d ",x);
	}
	puts("");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}