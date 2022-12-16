#include <stdio.h>
#include <algorithm>
#define MN 30000

void solve(){
	int n,c[3]={0,0,0},ans=0;
	scanf("%d",&n);
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		c[a%3]++;
	}
	for(int i=0;i<3;i++)
		c[i] -= n/3;
	for(int i=0,t=0;i<6;i++){
		if(c[i%3]>0){
			t += c[i%3];
			c[i] = 0;
		}
		if(c[i%3]<0){
			int r = std::min(t,-c[i%3]);
			t -= r;
			c[i%3] += r;
		}
		ans += t;
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}