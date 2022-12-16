#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 150000

using std::min,std::max;

const int INF = 0x3fffffff;

int n,lst[MN+5];

void solve(){
	memset(lst,0xff,sizeof(lst));
	scanf("%d",&n);
	int ans = 0;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(lst[a]!=-1){
			ans = max(ans,n-(i-lst[a]));
		}
		lst[a] = i;
	}
	if(ans==0){
		puts("-1");
	}else{
		printf("%d\n",ans);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}