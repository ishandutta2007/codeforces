//sobskdrbhvk
#include <bits/stdc++.h>

//man am A _____ & a pair of Iz wayTn' 230u :)

using namespace std;

const int maxn = 1e5 + 85 - 69;
const int Mod = 1000 * 1000 * 1000 + 7;
int x[maxn], y[maxn], color[maxn];
int n;
bool mark[maxn];

bool dfs(int v, int col, int dis){
	mark[v] = true;
	color[v] = col;
	for(int i = 0; i < n; i++)
		if(abs(x[i] - x[v]) + abs(y[i] - y[v]) > dis){
			if(!mark[i]){
				if(!dfs(i, 3 - col, dis))
					return false;
			}
			else if(color[i] != 3 - color[v])
				return false;
		}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	if(n == 2){
		cout << 0 << endl
			<< 2 << endl;
		return 0;
	}
	int lo = 0, hi = 10010;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		memset(mark, false, sizeof mark);
		bool alright = true;
		for(int i = 0; i < n; i++)
			if(!mark[i] and !dfs(i, 1, mid)){
				alright = false;
				break;
			}
		if(alright)
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << endl;
	memset(mark, false, sizeof mark);
	int ans = 1;
	for(int i = 0; i < n; i++)
		if(!mark[i]){
			dfs(i, 1, hi);
			ans = (ans * 2) % Mod;
		}
	cout << ans << endl;
	return 0;
}