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
#undef next
#define next NEXT

string s, t;
int next[100 * 1000 + 100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	int match = 0;
	for(int i = 1; i < sz(t); i++){
		while(match and t[i] != t[match])
			match = next[match - 1];
		match += t[i] == t[match];
		next[i] = match;
	}
	int ans = 0, last = -1;
	match = 0;
	for(int i = 0; i < sz(s); i++){
		while(match and s[i] != t[match])
			match = next[match - 1];
		match += s[i] == t[match];
		if(match == sz(t)){
			if(last <= i - sz(t)) ans++, last = i;
			match = next[match - 1];
		}
	}
	cout << ans << endl;
	return 0;
}