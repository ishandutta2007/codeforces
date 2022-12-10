//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 10;
vector<int> vec[maxn];
bool mark[maxn], hasodd;
int a[maxn];
int compon, min_comp;
int n;

void dfs(int v){
	mark[v] = true;
	vec[compon].PB(v);
	if(!mark[a[v]])
		dfs(a[v]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		if(!mark[i]){
			dfs(i);
			if(sz(vec[compon]) & 1)
				hasodd = true;
			if(sz(vec[compon]) < sz(vec[min_comp]))
				min_comp = compon;
			compon++;
		}
	if(hasodd and sz(vec[min_comp]) != 1){
		cout << "NO";
		return 0;
	}
	if(sz(vec[min_comp]) > 2){
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	int ptr = 0;
	for(int i = 0; i < compon; i++)
		if(i != min_comp)
			for(int j = 0; j < sz(vec[i]); j++, ptr = (ptr + 1) % sz(vec[min_comp]))
				cout << vec[min_comp][ptr] << ' ' << vec[i][j] << '\n';
	if(sz(vec[min_comp]) == 2)
		cout << vec[min_comp][0] << ' ' << vec[min_comp][1] << '\n';
	return 0;
}