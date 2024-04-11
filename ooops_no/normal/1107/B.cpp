/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;
typedef long long ll;

const ll INF = (ll) 1e18;

int main() {
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        cout << (a - 1) * 9 + b << endl;
	}
}