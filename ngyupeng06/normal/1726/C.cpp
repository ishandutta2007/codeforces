#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		string s;
		cin >> s;
		ll cnt = 0, sum = 0;
		for (int i=0; i<2*n-1; i++){
			if (s[i] == ')' && s[i+1] == '(') sum ++; 
		}
		cout << n - sum << nl;
		
	}
}