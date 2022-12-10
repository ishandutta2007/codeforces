#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 3e3 + 85;
bool foundrr = false;
vector<int> v[maxn];
int n;
queue<int> Q;
bool mark[maxn], mark2[maxn];
int par[maxn], h[maxn];

void dfs(int x){
	mark[x] = true;
	for(int i = 0; i < v[x].size() and !foundrr; i++){
		if(!mark[v[x][i]]){
			par[v[x][i]] = x;
			dfs(v[x][i]);
		}
		else if(v[x][i] != par[x]){
			int toprr, botrr;
			toprr = v[x][i];
			botrr = x;
			while(botrr != toprr){
				Q.push(botrr);
				mark2[botrr] = true;
				botrr = par[botrr];
			}
			Q.push(toprr);
			mark2[toprr] = true;
			foundrr= true;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int fi, se;
		cin >> fi >> se;
		v[fi].PB(se);
		v[se].PB(fi);
	}
	par[1] = -1;
	dfs(1);
	while(Q.size()){
		int x = Q.front();
		Q.pop();
		for(int i = 0; i < v[x].size(); i++){
			if(!mark2[v[x][i]]){
				h[v[x][i]] = h[x] + 1;
				mark2[v[x][i]] = true;
				Q.push(v[x][i]);
			}
		}
	}
	for(int i = 1; i <= n; i++)
		cout << h[i] << ' ';
	cout << endl;
	return 0;
}