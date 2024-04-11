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

string s;
int n;
bool mark1, mark2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s
		>> n;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		if (s == t) {
			cout << "YES";
			return 0;
		}
		if (t[0] == s[1])
			mark1 = true;
		if (t[1] == s[0])
			mark2 = true;
	}
	if (mark1 and mark2) {
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}