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

ll n, m, t, a, b, c;
ll arr[20][2];
ll hi[20];
ll tr[20];

ll ask(ll x) {
	cout << "? ";
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (i & hi[x]) v.pb(i);
	}
	cout << v.size() << " ";
	for (auto it : v){
		cout << it << " ";
	}
	cout << endl;
	string s;
	cin >> s;
	if (s == "YES") return 1;
	else return 0;
}

int main(){
	
	hi[0] = 1;
	for (int i =1;i<20; i++){
		hi[i] = hi[i-1] * 2;
	}

	cin >> n;
	
	int x = ask(0);
	
	int cur = 0;
	
	arr[0][1] = x;
	
	for (int i = 1; i <= 16; i++) {
		a = ask(i);
		b = ask(i);
		if (a == b) {
			arr[i][1] = a;
			tr[i] = 1;
			x = ask(0);
			continue;
		}
		c = ask(cur);
		if (c == x) {
			for (int j = cur+1; j < i; j++) {
				if (x != arr[cur][1]) swap(arr[j][1], arr[j][0]);
				tr[j] = 1;
			}
			
			arr[cur][1] = c;
			tr[cur] = 1;
			cur = i;
			x = ask(i);
			arr[i][1] = x;
			continue;
		}
		
		if (c == arr[cur][1]) {
			arr[i][1] = a, arr[i][0] = b;
		} else {
			arr[i][1] = b, arr[i][0] = a;
		}
		
		x = c;
	}
	ll ans = 0;
	for (int i=0; i<=16; i++){
		if (arr[i][1] == 1) {
			ans += hi[i];
		}
	}
	
	cout << "! " << ans << endl;
	string s;
	cin >> s;
	
	if (s == ":(") {
		ans = 0;
		for (int i=0; i<=16; i++){
			if (tr[i]){
				if (arr[i][1] == 1) ans += hi[i];
			}
			else {
				if (arr[i][1] == 0) ans += hi[i];
			}

		}
		cout << "! " << ans << endl;
		cin >> s;
	}
	
	return 0;
}