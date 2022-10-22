#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(v) v.begin(),v.end()

ll n, m, t;
map<ll, ll> ma;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		ma.clear();
		bool gd = true;
		for (int i=0; i<n; i++){

			int a;
			cin >> a;
						if (!gd) continue;
			ma[a]++;
			if (ma[a-m] || ma[a+m]) gd = false;
		}
		if (gd) cout << "no\n";
		else cout << "yes\n";
	}
}