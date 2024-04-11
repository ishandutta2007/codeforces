//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 5e5 + 10,
	  maxm = 1e6 + 10;
const LL Mod = 1e9 + 7;
int cnt[maxm];
map<int, int> go[maxn];
LL fact[maxm];
int n, m, sz = 1;
vector<int> vec[maxm];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	fact[0] = 1;
	for(int i = 1; i < maxm; i++)
		fact[i] = (fact[i - 1] * i) % Mod;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int c;
		cin >> c;
		for(int j = 0; j < c; j++){
			int x;
			cin >> x, x--;
			vec[x].PB(i);
		}
	}
	for(int i = 0; i < m; i++){
		int ptr = 0;
		for(auto val : vec[i]){
			if(go[ptr][val] == 0)
				go[ptr][val] = sz++;
			ptr = go[ptr][val];
		}
		cnt[ptr]++;
	}
	LL ans = 1;
	for(int i = 0; i < sz; i++)
		ans = (ans * fact[cnt[i]]) % Mod;
	cout << ans << '\n';
	return 0;
}