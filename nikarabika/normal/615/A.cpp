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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	set<int> s;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int cnt;
		cin >> cnt;
		for(int j = 0; j < cnt; j++){
			int x;
			cin >> x;
			s.insert(x);
		}
	}
	if(sz(s) == m)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}