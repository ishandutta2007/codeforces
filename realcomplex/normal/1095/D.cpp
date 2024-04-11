#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;

vector<int> T[N];

bool vis[N];

bool check(int a, int b){
	if(T[a][0] == b || T[a][1] == b)
		return true;
	return false;
}

void dfs(int u){
	if(vis[u])
		return;
	vis[u] = true;
	cout << u << " ";
	int a = T[u][0];
	int b = T[u][1];
	if(check(a, b))
		dfs(a);
	else
		dfs(b);
}

int main(){
	fastIO;
	int n;
	cin >> n;
	if(n == 3){
		cout << "1 2 3\n";
		return 0;
	}
	int p1, p2;
	for(int i = 1; i <= n; i ++ ){
		cin >> p1 >> p2;
		T[i].push_back(p1);
		T[i].push_back(p2);
	}
	dfs(1);
	return 0;
}