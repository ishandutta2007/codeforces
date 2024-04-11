#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

int n, q, k, a[100005];
int l, r;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> k;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	while (q--){
		cin >> l >> r;
		cout << k - (r-l+1) + a[r] - a[l] - r + l << "\n";
	}
}