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

const int N = (int)1e5 + 91;
vector<int> T[N];

int state[N];
vector<int> pp;

void dfs(int u){
	if(state[u] == 2)
		return;
	if(state[u] == 1){
		cout << "-1\n";
		exit(0);
	}
	state[u] = 1;
	for(auto x : T[u])
		dfs(x);
	pp.push_back(u);
	state[u] = 2;
}

int main(){
	fastIO;
	int n, k;
	cin >> n >> k;
	int p[k];
	for(int i = 0;i < k; i ++ )
		cin >> p[i];
	int ti;
	int s;
	for(int i = 1; i <= n; i ++ ){
		cin >> ti;
		for(int j = 0;j < ti; j ++ ){
			cin >> s;
			T[i].push_back(s);
		}
	}
	for(int i = 0;i < k; i ++ ){
		dfs(p[i]);
	}
	cout << pp.size() << "\n";
	for(auto x : pp)
		cout << x << " ";
	cout << "\n";
	return 0;
}