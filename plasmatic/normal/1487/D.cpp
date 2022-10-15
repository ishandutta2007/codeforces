// ./d-pythagorean-triples.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

bool check(ll a, ll b, ll c) {
    return a*a + b*b == c*c;
}

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (ll a = 1; a*a <= 3e9; a++) {
        if ((a*a + 1) % 2 == 0) {
            ll c = (a*a + 1) / 2, b = c-1;
            if (a <= b && b <= c && c <= 1e9 && check(a, b, c)) {
                // printf("N=%d found %lld %lld %lld\n", N,a,b,c);
                v.push_back(c);
            }
        }
    }
    sort(v.begin(), v.end());

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        int ans = upper_bound(v.begin(), v.end(), N) - v.begin();
        cout << ans << '\n';
    }

    return 0;
}