#include <stdio.h>
#include <string.h>
#include <vector>
#define MN 200000

using std::vector;

int n,a[MN+5],cnt[MN+5];

void solve(){
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	vector<int> ans;
	for(int i=1;i<=n;){
		int p = 0;
		while(cnt[p]) p++;
		vector<bool> vis(p,true);
		int t = 0;
		do{
			if(a[i]<p&&vis[a[i]]){
				vis[a[i]] = false;
				t++;
			}
			cnt[a[i]]--;
			i++;
		}while(t<p);
		ans.push_back(p);
	}
	printf("%d\n",(int)ans.size());
	for(int x:ans){
		printf("%d ",x);
	}
	puts("");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}