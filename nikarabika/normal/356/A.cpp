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

const int maxn = 3e5 + 85 - 69;
set<int> s;
int n, m,
	ans[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(ans, -1, sizeof ans);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		s.insert(i);
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th, fi--, th--;
		bool found = true;
		while(found){
			found = false;
			auto it = s.lower_bound(fi);
			if(it != s.end() and *it < se){
				ans[*it] = th;
				s.erase(it);
				found = true;
			}
		}
		s.insert(th);
		ans[th] = -1;
	}
	for(int i = 0; i < n; i++)
		cout << 1+ans[i] << ' ';
	cout << '\n';
	return 0;
}