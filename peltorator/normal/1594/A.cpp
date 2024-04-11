#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<ll> inp(istream_iterator<ll>(cin), {});
    vector<string> output(t);
    transform(inp.begin(), inp.end(), output.begin(), [](ll n) -> string {
            return to_string(-(n - 1)) + " " + to_string(n);
    });
    copy(output.begin(), output.end(), ostream_iterator<string>{cout, " "});
}