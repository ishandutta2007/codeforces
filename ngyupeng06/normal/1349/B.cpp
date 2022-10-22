#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long t, n, k, arr[100005], val[100005], pref1[100005], pref2[100005], m1[100005], m2[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> k;
		pref2[n+1] = 0;
		for (int i=0; i<=n+1; i++){
			m1[i] = m2[i] = -1e9;
		}
		bool bruh = false;
		for (int i=1; i<=n; i++){
			cin >> arr[i];
			if (arr[i] == k) bruh = true;
			if (arr[i] >= k) val[i] = 1;
			else val[i] = -1;
			pref1[i] = pref1[i-1] + val[i];
		}
		if (!bruh){
			cout << "no\n";
			continue;
		}
		if (bruh && n==1 && arr[1] == k){
			cout << "yes\n";
			continue;
		}
		long long cmin = 0;
		bool gd = false;
		for (int i=2; i<=n; i++){
			if (pref1[i] - cmin > 0) gd = true;
			cmin = min(cmin,pref1[i-1]);
		}
		if (gd) cout << "yes\n";
		else cout << "no\n";
	}
}