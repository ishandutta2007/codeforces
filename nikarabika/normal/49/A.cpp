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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	vector<pii> vec;
	getline(cin, s);
	for(int i = 0; i < sz(s); i++){
		char &c = s[i];
		if(c >= 'A' and c <= 'Z')
			c += 'a' - 'A';
	}
	reverse(all(s));
	for(int i = 0; i < 26; i++)
		vec.PB(MP(find(all(s), 'a' + i) - s.begin(), i));
	sort(all(vec));
	string x = "aeiouy";
	if(count(all(x), 'a' + vec[0].R) > 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}