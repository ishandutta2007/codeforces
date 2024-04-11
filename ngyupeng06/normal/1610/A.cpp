#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

int n, m, k, t, a, b, c;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> a >> b;
		if (a==b && a==1) cout << 0;
		else if (min(a,b) == 1) cout << 1;
		else cout << 2;
		cout << "\n";
	}
}