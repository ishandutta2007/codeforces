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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int n;
	cin >> n >> s;
	int ans = 0;
	while(1){
		int up = count(all(s), 'x'),
			dn = count(all(s), 'X');
		if(up > dn){
			int id = find(all(s), 'x') - s.begin();
			s[id] = 'X';
		}
		else if(up == dn) break;
		else{
			int id = find(all(s), 'X') - s.begin();
			s[id] = 'x';
		}
		ans++;
	}
	cout << ans << endl;
	cout << s << '\n';
	return 0;
}