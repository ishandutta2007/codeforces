#include <stdio.h>
#include <vector>

int u,v;

void solve(){
	scanf("%d%d",&u,&v);
	if(u>v){
		puts("NO");
		return;
	}
	std::vector<int> p[2];
	for(int i=0;i<30;i++)
		if(u&(1<<i)) p[0].push_back(i);
	for(int i=0;i<30;i++)
		if(v&(1<<i)) p[1].push_back(i);
	if(p[1].size()>p[0].size()){
		puts("NO");
		return;
	}
	for(int i=0;i<(int)p[1].size();i++){
		if(p[0][i]>p[1][i]){
			puts("NO");
			return;
		}
	}
	puts("YES");
	return;
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}