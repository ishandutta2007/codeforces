//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
#define plus Plu

vector<int> ans, an;

int dist(int i, int j){
	if(i < j)
		return j - i;
	return 10 - (i - j);
}

void plus(int ptr, int val){
	ans[ptr] += val;
	if(ans[ptr] >= 10){
		plus(ptr + 1, ans[ptr] / 10);
		ans[ptr] %= 10;
	}
	return;
}

void solve(int ptr){
	if(ptr == sz(an))
		return;
	plus(ptr, dist(ans[ptr], an[ptr]));
	solve(ptr + 1);
	return;
}

void solve(void){
	an.clear();
	ans.clear();
	string s;
	cin >> s;
	ans.PB(8);
	ans.PB(8);
	ans.PB(9);
	ans.PB(1);
	for(int i = 0; i < 20; i++)
		ans.PB(0);
	for(int i = sz(s) - 1; i >= 4; i--)
		an.PB(s[i] - '0');
	solve(0);
	bool x = false;
	for(int i = sz(ans) - 1; i >= 0; i--){
		if(ans[i])
			x = true;
		if(x) cout << ans[i];
	}
	cout << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	an.reserve(100);
	ans.reserve(100);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}