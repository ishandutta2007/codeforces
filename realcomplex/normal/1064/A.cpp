#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	int t[3];
	cin >> t[0] >> t[1] >> t[2];
	sort(t, t + 3);
	int v1 = t[2] - t[1];
	int answ = max(0, (v1 + 1) - t[0]);
	cout << answ;
	return 0;
}