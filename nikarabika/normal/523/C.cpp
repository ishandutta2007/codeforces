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

string s, t;
const int maxn = 1000 * 1000 + 100;
int l[maxn], r[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t;
	int ptr = -1;
	for(int i = 0; i < sz(t); i++){
		if(ptr + 1 < sz(s) and t[i] == s[ptr + 1]) ptr++;
		l[i] = ptr + 1;
	}
	ptr = sz(s);
	for(int i = sz(t) - 1; i >= 0; i--){
		if(ptr - 1 >= 0 and t[i] == s[ptr - 1]) ptr--;
		r[i] = sz(s) - ptr;
	}
	int ans = 0;
	for(int i = 0; i + 1 < sz(t); i++)
		if(l[i] == sz(s) and r[i + 1] == sz(s))
			ans++;
	cout << ans << endl;
	return 0;
}