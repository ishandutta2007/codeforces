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

int m[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x;
	string s;
	cin >> x >> s >> s;
	if(s == "week"){
		int ans = 0;
		for(int i = 5; i <= 366 + 4; i++)
			if(i % 7 == x % 7)
				ans++;
		cout << ans << endl;
		return 0;
	}
	sort(m, m + 12);
	cout << m + 12 - lower_bound(m, m + 12, x) << endl;
	return 0;
}