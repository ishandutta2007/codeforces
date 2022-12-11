#include <bits/stdc++.h>

using namespace std;

const int N = 123456;
vector<int>edg[N];
int colors[N];
vector<int>ver[2];

void ini(){
	for(int j = 0;j<N;j++)colors[j]=-10;
}

void dfs(int cur,int bit){
	ver[bit].push_back(cur);
	colors[cur]=bit;
	bit = 1-bit;
	for(int x : edg[cur]){
		if(colors[x]==colors[cur]){
			cout << -1 << endl;
			exit(0);
		}
		if(colors[x]==-10){
			dfs(x,bit);
		}
	}
}

int main(){
	ini();
	int n,m;
	cin >> n >> m;
	int a,b;
	for(int j = 0;j<m;j++){
		cin >> a >> b;
		edg[a].push_back(b);
		edg[b].push_back(a);
	}	
	for(int i = 1;i<=n;i++)
		if(colors[i]==-10&&!edg[i].empty())dfs(i,0);
	for(int j = 0;j<2;j++){
		cout << ver[j].size() << endl;
		for(int x : ver[j])cout << x << " ";
		cout << endl;
	}
	return 0;
}