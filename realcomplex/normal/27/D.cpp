#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

const int N = 100;
vector<int> T[N];

int bit[N];

void dfs(int u, int b){
	if(bit[u] == -1)
		bit[u] = b;
	else{
		if(bit[u] != b){
			cout << "Impossible\n";
			exit(0);
		}
		return;
	}
	for(auto x : T[u]){
		
		dfs(x, 1 - b);
	}
}

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	int a[m], b[m];
	for(int i = 0 ; i < m; i ++ ){
		cin >> a[i] >> b[i];
		-- a[i];
		-- b[i];
		if(a[i] > b[i])
			swap(a[i], b[i]);
	}
	int l, r, al, bl;
	for(int i = 0 ; i < m;i ++ ){
		for(int j = 0 ; j < m; j ++ ){
			if(i == j)
				continue;
			if(a[i] > a[j] and a[i] < b[j] and b[i] > b[j]){
				T[i].push_back(j);
				T[j].push_back(i);
	
			}
			
		}
	}
	for(int i = 0 ; i < m ; i ++ ){
		bit[i] = -1;
	}
	for(int i = 0 ; i < m ; i ++ ){
		if(bit[i] == -1)
			dfs(i, 0);
	}
	for(int i = 0 ; i < m ; i ++ ){
		if(bit[i] == 0)
			cout << "i";
		else
			cout << "o";
	}
	return 0;
}