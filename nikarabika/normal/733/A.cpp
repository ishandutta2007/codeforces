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
	string vow = "AEIOUY";
	string s;
	cin >> s;
	int ans = -1;
	int lst = -1;
	for(int i = 0; i < sz(s); i++){
		if(count(all(vow), s[i]) == 1){
			smax(ans, i - lst);
			lst = i;
		}
	}
	smax(ans, sz(s) - lst);
	cout << ans << '\n';
	return 0;
}