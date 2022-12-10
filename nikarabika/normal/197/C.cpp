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

string s;

int fmax(int i, int j){
	return -max(MP(s[i], -i), MP(s[j], -j)).R;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int Max[sz(s) + 10];
	Max[sz(s)] = sz(s);
	s += char('a' - 1);
	for(int i = sz(s) - 2; i >= 0; i--)
		Max[i] = fmax(Max[i + 1], i);
	int p = Max[0];
	while(p < sz(s) - 1){
		cout << s[p];
		p = Max[p + 1];
	}
	return 0;
}