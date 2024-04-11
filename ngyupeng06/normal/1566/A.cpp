#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, m, t, s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i=0; i<t; i++){
		cin >> n >> s;
		cout << (s / (n/2 + 1)) << "\n";
	}
}