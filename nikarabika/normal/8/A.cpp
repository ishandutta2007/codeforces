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
	string s, t1, t2;
	cin >> s >> t1 >> t2;
	int ans = 0;
	int lst = -1,
		fir = sz(s);
	for(int i = 0; i < sz(s); i++){
		if(i + sz(t1) <= sz(s) and s.substr(i, sz(t1)) == t1)
			smin(fir, i);
		if(i + sz(t2) <= sz(s) and s.substr(i, sz(t2)) == t2)
			smax(lst, i);
	}
	if(fir + sz(t1) <= lst)
		ans += 1;
	reverse(all(s));
	lst = -1, fir = sz(s);
	for(int i = 0; i < sz(s); i++){
		if(i + sz(t1) <= sz(s) and s.substr(i, sz(t1)) == t1)
			smin(fir, i);
		if(i + sz(t2) <= sz(s) and s.substr(i, sz(t2)) == t2)
			smax(lst, i);
	}
	if(fir + sz(t1) <= lst)
		ans += 2;
	if(ans == 3)
		cout << "both\n";
	else if(ans == 2)
		cout << "backward\n";
	else if(ans == 1)
		cout << "forward\n";
	else
		cout << "fantasy\n";
	return 0;
}