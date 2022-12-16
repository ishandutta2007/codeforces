#include <stdio.h>
#include <map>
#define MN 200000
#define MM 200000

int n,m,ans1,ans2;
std::map<int,int> mp[MN+5];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		char o;
		scanf(" %c",&o);
		if(o=='?'){
			int k;
			scanf("%d",&k);
			if(k&1){
				puts(ans1?"YES":"NO");
			}else{
				puts(ans2?"YES":"NO");
			}
		}else{
			int u,v;
			scanf("%d%d",&u,&v);
			if(o=='+'){
				char c;
				scanf(" %c",&c);
				if(mp[v].find(u)!=mp[v].end()){
					ans1++;
					if(mp[v][u]==c){
						ans2++;
					}
				}
				mp[u][v] = c;
			}else{
				if(mp[v].find(u)!=mp[v].end()){
					ans1--;
					if(mp[v][u]==mp[u][v]){
						ans2--;
					}
				}
				mp[u].erase(v);
			}
		}
	}
}