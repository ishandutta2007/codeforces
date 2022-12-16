#include <stdio.h>
#include <algorithm>
#define MN 200000

int n,h[MN+5],ans[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	std::sort(h+1,h+1+n);
	int mindiff = 1e9;
	int pos = -1;
	for(int i=2;i<=n;i++){
		int diff = std::abs(h[i]-h[i-1]);
		if(diff<mindiff){
			mindiff = diff;
			pos = i;
		}
	}
	if(n==2||n==3||n==4){
		int best = 0;
		if(n==2){
			ans[1] = h[1];
			ans[2] = h[2];
		}
		if(n==3){
			for(int t=1;t<=6;t++,std::next_permutation(h+1,h+1+n)){
				if(std::abs(h[1]-h[n])!=mindiff) continue;
				int cnt = 0;
				for(int i=2;i<=n;i++){
					if(h[i-1]<=h[i]) cnt++;
				}
				if(cnt>best){
					best = cnt;
					for(int i=1;i<=n;i++)
						ans[i] = h[i];
				}
				std::next_permutation(h+1,h+1+n);
			}
		}
		if(n==4){
			for(int t=1;t<=24;t++,std::next_permutation(h+1,h+1+n)){
				if(std::abs(h[1]-h[n])!=mindiff) continue;
				int cnt = 0;
				for(int i=2;i<=n;i++){
					if(h[i-1]<=h[i]) cnt++;
				}
				if(cnt>best){
					best = cnt;
					for(int i=1;i<=n;i++)
						ans[i] = h[i];
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			ans[i] = h[(pos+i-2)%n+1];
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d%c",ans[i]," \n"[i==n]);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}