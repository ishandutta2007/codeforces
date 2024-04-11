#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++){
		string s;
		cin >> s;
		char prev = '2';
		int cnt = 0;
		bool gd = false;
		for (int i=0; i<s.length(); i++){
			if (s[i] == '0') gd = true;
			if (s[i] == '0' && prev != s[i]) cnt++;
			prev = s[i];
		}
		if (!gd) cout << "0\n";
		else if (cnt < 2) cout << "1\n";
		else cout << "2\n";
	}
}