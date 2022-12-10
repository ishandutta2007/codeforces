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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	for(int i = 0; i < sz(s); i++){
		if(s[i] - 'a' > 'z' - s[i]){
			int val = min(s[i] - 'a', k);
			k -= val;
			s[i] -= val;
		}
		else{
			int val = min('z' - s[i], k);
			k -= val;
			s[i] += val;
		}
	}
	if(k)
		cout << -1;
	else
		cout << s;
	return 0;
}