#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 105;
vector<int> T[N];
bool vis[N];

void dfs(int u){
	vis[u] = true;
	for(auto x : T[u]){
		if(!vis[x]){
			dfs(x);
		}
	}
}

int ky[N];

int main(){
	fastIO;
	int q;
	cin >> q;
	int t[q], x[q], y[q];
	int p = 1;
	for(int i = 0;i < q;i ++ ){
		cin >> t[i] >> x[i] >> y[i];
		if(t[i] == 1){
			ky[p ++ ] = i;
			for(int j = 0;j < i ; j ++ ){
				if((x[j] > x[i] and x[j] < y[i]) or (y[j] > x[i] and y[j] < y[i])){
					T[j].push_back(i);
				}
				if((x[i] > x[j] and x[i] < y[j]) or (y[i] > x[j] and y[i] < y[j])){
					T[i].push_back(j);
				}
			}
		}
		else{
			for(int j = 0;j < q;j ++ ){
				vis[j] = false;
			}
			dfs(ky[x[i]]);
			if(vis[ky[y[i]]]){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
	return 0;
}