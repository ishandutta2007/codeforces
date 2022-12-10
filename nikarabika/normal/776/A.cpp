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
	string s, t;
	int n;
	cin >> s >> t
		>> n;
	for(int i = 1; i <= n; i++){
		cout << s << ' ' << t << '\n';
		string ss, tt;
		cin >> ss >> tt;
		if(ss == s) s = tt;
		else t = tt;
	}
	cout << s << ' ' << t << endl;
	return 0;
}