#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;

int main() {
    //ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    cout << sum % 2 << "\n";
    sum /= 2;
    vector<ll> ans;
    for (ll i = n; i > 0; --i)
        if (sum >= i) {
            sum -= i;
            ans.push_back(i);
        }
    cout << ans.size() << ' ';
    for (auto i : ans) cout << i << ' ';
    //system("pause");
    return 0;
}