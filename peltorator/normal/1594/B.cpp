#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))

using namespace std;
typedef long long ll;

struct mypair : std::pair<uint32_t, uint32_t> {
    using std::pair<uint32_t, uint32_t>::pair;
};

std::istream& operator>>(std::istream& stream, mypair& in) {
    return stream >> in.first >> in.second;
}

std::ostream& operator<<(std::ostream& stream, const mypair& in) {
    return stream << in.first << ' ' << in.second;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<mypair> inp(istream_iterator<mypair>(cin), {});

    vector<ll> output(t);
    const ll MOD = 1e9 + 7;
    transform(inp.begin(), inp.end(), output.begin(), [&](mypair p) -> ll {
            uint32_t n = p.first, k = p.second;
            string bkstring = bitset<32>(k).to_string();
            vector<int> bk(32);
            transform(bkstring.begin(), bkstring.end(), bk.begin(), [](char ch) -> int {
                return ch - '0';
            });
            reverse(bk.begin(), bk.end());
            vector<int> inds(32);
            iota(inds.begin(), inds.end(), 0);
            vector<pair<int, int>> bk_with_inds(32);
            std::transform(bk.begin(), bk.end(), inds.begin(), bk_with_inds.begin(), [](const int& a, const int& b) {
                   return pair<int, int>{a, b};
            });
            function<int(int, int)> binpow = [&](int a, int b) -> int {
                if (b == 0) {
                    return 1;
                }
                if (b & 1) {
                    return 1LL * binpow(a, b - 1) * a % MOD;
                }
                return binpow(1LL * a * a % MOD, b >> 1);
            };
            return accumulate(bk_with_inds.begin(), bk_with_inds.end(), 0LL, [&](int curval, pair<int, int> p) -> int {
                    return (curval + p.first * binpow(n, p.second)) % MOD;
            });
    });
    copy(output.begin(), output.end(), ostream_iterator<ll>{cout, "\n"});
}