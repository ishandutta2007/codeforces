#include <stdio.h>
#include <algorithm>
#include <set>
#define MN 200000
int n,m,ans=-1;
std::set<int> s[MN+5];
int f[MN+5];
int gf(int x){
	return f[x]==x?x:f[x]=gf(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		s[a].insert(i);
	}
	for(int i=1;i<=m;i++){
		int lst = -1;
		for(auto x:s[i]){
			if(x-lst > 1) ans++;
			lst = x;
		}
		f[i] = i;
	}
	printf("%d\n",ans);
	for(int t=1,a,b;t<=m-1;t++){
		scanf("%d%d",&a,&b);
		
		a=gf(a),b=gf(b);
		if(s[a].size()<s[b].size())
			std::swap(a,b);
		f[b] = a;
		
		int lst = -1;
		for(auto x:s[b]){
			if(x-lst > 1){
				//r
				if(lst != -1){
					if(s[a].find(lst+1) != s[a].end()) ans--;
				}
				//l
				if(s[a].find(x-1) != s[a].end()) ans--;
				//upd
			}
			lst = x;
			s[a].insert(x);
		}
		//r
		if(s[a].find(lst+1) != s[a].end()) ans--;
		printf("%d\n",ans);
	}
}