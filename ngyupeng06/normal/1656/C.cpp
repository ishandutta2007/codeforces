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
ll arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		bool gd = true;
		for(int i=0; i<n; i++){
			cin >> arr[i];
			if (arr[i] == 1) gd = false;
		}
		if (gd) cout << "yes\n";
		else {
		
		sort(arr, arr+n);
		bool gd1 = false;
		for (int i=1; i<n; i++){
			if (arr[i-1]+1==arr[i]) gd = true;
		}
		if (gd) cout << "no\n";
		else cout << "yes\n";
		
	}
	}
}