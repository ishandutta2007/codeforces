#include <stdio.h>
#include <vector>
#define MN 100000
#define MM 100000

int n,m,a[MN+5],b[MN+5],c[MM+5],ans[MM+5];
std::vector<int> toPaint[MN+5];

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&c[i]);
	ans[m] = -1;
	for(int i=1;i<=n;i++){
		if(b[i]==c[m]){
			ans[m] = i;
			if(a[i]!=b[i]){
				a[i] = c[m];
				break;
			}
		}
	}
	if(ans[m]==-1){
		puts("NO");
		return;
	}
	for(int i=1;i<=n;i++)
		toPaint[i].clear();
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			toPaint[b[i]].push_back(i);
		}
	}
	for(int i=1;i<=m-1;i++){
		if(toPaint[c[i]].size()){
			ans[i] = toPaint[c[i]].back();
			toPaint[c[i]].pop_back();
		}else{
			ans[i] = ans[m];
		}
	}
	for(int i=1;i<=n;i++){
		if(toPaint[i].size()){
			puts("NO");
			return;
		}
	}
	puts("YES");
	for(int i=1;i<=m;i++){
		printf("%d%c",ans[i]," \n"[i==m]);
	}
	return;
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}