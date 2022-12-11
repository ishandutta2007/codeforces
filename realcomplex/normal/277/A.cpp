#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
vector<int>b1[MAXN],b2[MAXN];
bool vis[MAXN];

void dfs(int c,int bit){
	if(bit==1){
		vis[c] = true;
		for(auto x : b1[c])
			dfs(x,!bit);
	}
	else{
		for(auto x : b2[c])
			if(!vis[x])
				dfs(x,!bit);
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	int l,k;
	int s = 0;
	for(int j = 1;j<=n;j++){
		cin >> l;s+=l;
		for(int i = 0;i<l;i++){
			cin >> k;
			b1[j].push_back(k);
			b2[k].push_back(j);
		}
	}
	int language = 0;
	for(int j = 1;j<=n;j++){
		if(!vis[j]){
			language++;
			dfs(j,1);
		}
	}
	if(s==0)cout << n;
	else cout << language-1;
	cout << endl;
	return 0;	
}