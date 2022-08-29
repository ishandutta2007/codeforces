#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };

struct safe_hash32 {
    static unsigned hash32(unsigned x) {
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        return x ^ (x >> 16);
    }

    unsigned operator()(unsigned x) const {
        static const unsigned FIXED_RANDOM = hash32(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
        return hash32(x ^ FIXED_RANDOM);
    }
};

const int K_MAX = 15, MASK_MAX = 1 << K_MAX;

int K, N[K_MAX];
vector<int> A[K_MAX];
long long sums[K_MAX];
gp_hash_table<int, int, safe_hash32> location;
vector<pair<int, int>> solutions[MASK_MAX];

bool valid(int mask) {
    if ((int) solutions[mask].size() < K)
        return false;

    for (int prefix = mask; prefix != 0; prefix &= prefix - 1) {
        int bit = __builtin_ctz(prefix);

        if (solutions[mask][bit].second == 0)
            return false;
    }

    return true;
}

void combine(const vector<pair<int, int>> &x, const vector<pair<int, int>> &y, vector<pair<int, int>> &z) {
    z.resize(K);

    for (int k = 0; k < K; k++)
        z[k] = {x[k].first + y[k].first, x[k].second + y[k].second};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    long long total_sum = 0;

    for (int k = 0; k < K; k++) {
        cin >> N[k];
        A[k].resize(N[k]);
        sums[k] = 0;

        for (int &a : A[k]) {
            cin >> a;
            location[a] = k;
            sums[k] += a;
        }

        total_sum += sums[k];
    }

    if (total_sum % K != 0) {
        cout << "No" << '\n';
        return 0;
    }

    long long target = total_sum / K;

    for (int k = 0; k < K; k++)
        for (int initial : A[k]) {
            vector<pair<int, int>> solution(K, {0, 0});
            int mask = 1 << k;
            int current = k;
            long long need = target - (sums[current] - initial);
            bool failed = false;

            while (true) {
                if (need != (int) need || location.find(need) == location.end()) {
                    failed = true;
                    break;
                }

                int index = location[need];
                solution[index] = {(int) need, current + 1};

                if (mask >> index & 1) {
                    failed = index != k || need != initial;
                    break;
                }

                mask |= 1 << index;
                current = index;
                need = target - (sums[current] - need);
            }

            if (!failed)
                solutions[mask] = solution;
        }

    for (int mask = 1; mask < 1 << K; mask++)
        if (!valid(mask))
            for (int sub = mask; ; sub = (sub - 1) & mask) {
                int other = mask ^ sub;

                if (valid(sub) && valid(other)) {
                    combine(solutions[sub], solutions[other], solutions[mask]);
                    break;
                }

                if (sub == 0)
                    break;
            }

    if (!valid((1 << K) - 1)) {
        cout << "No" << '\n';
        return 0;
    }

    cout << "Yes" << '\n';
    vector<pair<int, int>> solution = solutions[(1 << K) - 1];

    for (pair<int, int> &p : solution)
        cout << p.first << ' ' << p.second << '\n';
}