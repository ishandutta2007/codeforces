#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, a, b;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m;
	while (m--){
		cin >> a >> b;
		if (b<a){
			cout << "NO\n";
			continue;
		}
		vector<int> va, vb;
		for (int i=0; i<30; i++){
			if (a & (1<<i)) va.pb(i);
			if (b & (1<<i)) vb.pb(i);
		}
		if (va.size() < vb.size()){
			cout << "NO\n";
			continue;
		}
		bool gd = true;
		for (int i=0; i<vb.size(); i++){
			if (va[i] > vb[i]) gd = false;
		}
		if (gd) cout << "YES\n";
		else cout << "NO\n";
	}
}