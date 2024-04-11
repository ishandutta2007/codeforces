#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<int> distinct_prime_factors(int num) {
    vector<int> ans;
    for (int div = 2; div * div <= num;) {
        if (num % div == 0) {
            if (ans.size() == 0 || ans.back() != div)
                ans.push_back(div);
            num /= div;
        }
        else
            div++;
    }
    if (ans.size() == 0 || ans.back() != num) {
        ans.push_back(num);
    }
    return ans;
}

int get_bit(int num, int bit) {
    return (num >> bit) & 1;
}

void set_bit(int& num, int bit, int val) {
    if (get_bit(num, bit) != val)
        num ^= 1 << bit;
}

int bit_count(int num) {
    return bitset<32>(num).count();
}

int coprimes_until(const int num, const vector<int>& primes) {
    int ans = num;
    for (int mask = 1; mask < 1 << primes.size(); mask++) {
        int div = 1;
        for (int bit = 0; bit < primes.size(); bit++) {
            if (get_bit(mask, bit)) {
                div *= primes[bit];
            }
        }
        ans += (num / div) * (bit_count(mask) % 2 == 0 ? 1 : -1);
    }
    return ans;
}

void solve(const int x, const int p, const int k) {
    const auto factors = distinct_prime_factors(p);

    const int until_x = coprimes_until(x, factors);

    int lo = x;
    int hi = 1e9;

    while (lo != hi) {
        int mid = (lo + hi + 1) / 2;
        int ans = coprimes_until(mid, factors);
        if (ans < k + until_x) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << lo + 1 << "\n";
}

int main() {
    /*
    int n, k;
    cin >> n >> k;
    auto dpf = distinct_prime_factors(k);
    auto ans = coprimes_until(n, dpf);
    cout << ans << "\n";
    */

    int t;
    cin >> t;
    while (t--) {
        int x, p, k;
        cin >> x >> p >> k;
        if (p==1) {
            cout << x+k << "\n";
        }
        else {
            solve(x, p, k);
        }
    }

}