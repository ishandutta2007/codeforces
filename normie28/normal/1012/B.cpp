#include <bits/stdc++.h>
 
using namespace std;
 
int N,M,Q;
pair<int,int> V[2000005];
vector<int> G[4000005];
bool viz[4000005];
 
void dfs(int nod){
	viz[nod] = 1;
	for(auto it:G[nod]){
		if(!viz[it]){
			dfs(it);
		}
	}
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> N >> M >> Q;
	for(int i = 1;i <= Q;i++){
		int x,y;
		cin >> x >> y;
		G[x].push_back(y + N);
		G[y + N].push_back(x);
	}
	
	int comp = 0;
	
	for(int i = 1;i <= N +  M;i++){
		if(!viz[i]){
			comp++;
			dfs(i);
		}
	}
	cout << comp - 1;
}