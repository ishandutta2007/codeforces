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

const int maxn = 5e5 + 10;
LL mintime[maxn], n, k, st[maxn], en[maxn], m[maxn];
set<pll> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> st[i] >> m[i];
	for(int i = 0; i < k; i++)
		s.insert(MP(0LL, i));
	for(int i = 0; i < n; i++){
		int id = s.begin()->R;
		mintime[id] = max(s.begin()->L, st[i]) + m[i];
		en[i] = mintime[id];
		s.erase(s.begin());
		s.insert(MP(mintime[id], id));
	}
	for(int i =0; i < n; i++)
		cout << en[i] << '\n';
	return 0;
}