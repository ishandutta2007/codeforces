#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	
	cin >> n;
    ll sum = 0;
    for(i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
    }

    vector<ll> sol(n);
    for(i = 0; i < n; i++) {
        sol[i] = i;
        sum -= i;
    }
    for(i = 0; i < n; i++) {
        sol[i] += sum / n;
    }
    sum %= n;
    for(i = 0; i < sum; i++) {
        sol[i]++;
    }
    for(i = 0; i < n; i++) {
        cout << sol[i] << " ";
    }

    return 0;
}