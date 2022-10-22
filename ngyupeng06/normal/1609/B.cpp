#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, k, t, a, b, c;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> s;
	ll l = s.length();
	ll cnt = 0;
	for (int i=0; i<n-2; i++){
		if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') cnt++;
	}
	while(m--){
		char x;
		cin >> a >> x;
		a--;
		ll x1 = 0, x2 = 0;
		for (int i=a-2; i<=a; i++){
			if (i < 0 || i >= n-2) continue;
			if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') x1++;
		}
		s[a] = x;
		for (int i=a-2; i<=a; i++){
			if (i < 0 || i >= n-2) continue;
			if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') x2++;
		}
		cnt -= x1 - x2;
		cout << cnt << "\n";
	}
}