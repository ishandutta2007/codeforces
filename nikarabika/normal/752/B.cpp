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

int match[256];
string s, t;
vector<pair<char, char>> ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(match, -1, sizeof match);
	cin >> s
		>> t;
	for(int i = 0; i < sz(s); i++){
		if((~match[s[i]] and match[s[i]] != t[i]) or (~match[t[i]] and match[t[i]] != s[i])){
			cout << -1 << endl;
			return 0;
		}
		match[s[i]] = t[i];
		match[t[i]] = s[i];
	}
	for(int i = 0; i < 128; i++)
		if(i < match[i])
			ans.PB(MP(char(i), char(match[i])));
	cout << sz(ans) << endl;
	for(auto P : ans)
		cout << P.L << ' ' << P.R << endl;
	return 0;
}