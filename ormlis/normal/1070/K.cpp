#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 100, SZ = 1e5 + 100;

ll n, k;
vector<ll> vec;

int main() {
    fastInp;

    cin >> n >> k;

    vec.resize(n);

    for (auto& c : vec) cin >> c;

    ll sm = 0, cnt = 0;

    ll s = 0;
    for (auto c : vec) s += c;

    if (s % k == 0) {
        k = s / k;
    }
    else {
        cout << "No";
        return 0;
    }

    vector<ll> ans;

    for (int i = 0; i < vec.size(); i++) {
        sm += vec[i];
        cnt++;
        if (sm == k) {
            ans.push_back(cnt);
            cnt = 0;
            sm = 0;
        }
    }

    if (sm != 0) {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";
    for (auto c : ans) cout << c << " ";

    return 0;
}