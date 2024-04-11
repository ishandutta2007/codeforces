#include <bits/stdc++.h>
using namespace std;
const int maxn=213456;
int p[maxn], deg[maxn], n;
vector<int> G[maxn], t;
void dfs(int u){
	for(int v:G[u])
		dfs(v);
	t.push_back(u);
}
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n;
	if(n%2==0){
		puts("NO");
		return 0;
	}
	puts("YES");
	int r=1;
	for(int i=1; i<=n; i++){
		cin>>p[i];
		deg[p[i]]++;
		if(p[i]) deg[i]++;
		else r=i;
		G[p[i]].push_back(i);
	}
	dfs(r);
	vector<int> ans1, ans2;
	for(int u:t){
		if(deg[u]&1) ans1.push_back(u);
		else{
			ans2.push_back(u);
			deg[p[u]]--;
		}
	}
	for(int u:ans2) printf("%d\n", u);
	reverse(ans1.begin(), ans1.end());
	for(int u:ans1) printf("%d\n", u);
	return 0;
}