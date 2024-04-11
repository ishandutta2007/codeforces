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

int s[10];
int mp[10][10];
int ans, n, q;

bool check(void){
	int lastchar = s[0];
	for(int i = 1; i < n; i++){
		if(~mp[lastchar][s[i]])
			lastchar = mp[lastchar][s[i]];
		else
			return false;
	}
	return lastchar == 0;
}

void build(int pos = 0){
	if(pos == n){
		ans += check();
		return;
	}
	for(int i = 0; i < 6; i++){
		s[pos] = i;
		build(pos + 1);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(mp, -1, sizeof mp);
	cin >> n >> q;
	for(int i = 0; i < q; i++){
		string x;
		char xx;
		cin >> x >> xx;
		mp[x[0] - 'a'][x[1] - 'a'] = xx - 'a';
	}
	build();
	cout << ans << endl;
	return 0;
}