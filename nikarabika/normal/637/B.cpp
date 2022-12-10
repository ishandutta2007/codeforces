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

const int maxn = 2e5;
vector<string> alls;
string s[maxn];
int n;
int cnt[maxn], order[maxn];

bool cmp(int i, int j){
	return cnt[i] > cnt[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		alls.PB(s[i]);
		order[i] = i;
	}
	sort(all(alls));
	alls.resize(unique(all(alls)) - alls.begin());
	for(int i = 0; i < n; i++){
		int id = lower_bound(all(alls), s[i]) - alls.begin();
		cnt[id] = i;
	}
	sort(order, order + sz(alls), cmp);
	for(int i = 0; i < sz(alls); i++)
		cout << alls[order[i]] << '\n';
	return 0;
}