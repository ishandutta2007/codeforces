#include<iostream>
#include<vector>
using namespace std;
const int maxn = 3e5 + 50;
//vector<int> v[maxn];
int c[maxn];
int id[maxn];
int p[maxn];
int n,m;
vector<int> g[maxn];
int ex[maxn] = {0};
int main(){
	cin>>n>>m;
	int ans = 0;
	for(int i = 1;i <= n;++i) {
		c[i] = 0;
		scanf("%d",&p[i]);
		id[p[i]] = i;
	}
	for(int i = 0;i < m;++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		if(id[v] > id[u]) g[id[u]].push_back(id[v]);
	}
	int k = n;
	for(int i = n-1;i > 0; --i){
		int cnt = 0;
		for(int j = 0;j < g[i].size();++j){
			if(!ex[g[i][j]]) cnt++;
		}
		if(cnt == k - i){
			ex[i] = 1;++ans;k--;
		}
	}
	cout<<ans;
}