#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

const int M = 1000000007;

int LIM = 200;

long long allgcd(const vector<int>& a) {
    int n = a.size();
    if (n < LIM) {
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res += a[i];
            for (int j = i + 1; j < n; ++j) {
                res += gcd(a[i], a[j]) * 2;
            }
        }
        return res % M;
    }
    else {
        vector<int> cnt(100010);
        for (auto& i : a) {
            ++cnt[i];
        }
        for (int i = 1; i < 100010; ++i) {
            for (int j = i * 2; j < 100010; j += i) {
                cnt[i] += cnt[j];
            }
        }
        vector<long long> sum(100010);
        for (int i = 100010 - 1; i > 0; --i) {
            sum[i] = cnt[i] * (long long)cnt[i];
            for (int j = i * 2; j < 100010; j += i) {
                sum[i] -= sum[j];
            }
        }
        long long res = 0;
        for (int i = 1; i < 100010; ++i) {
            res = (res + i * (sum[i] % M)) % M;
        }
        return res;
    }
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    // n = 100000;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        // a[i] = i + 1;
        cin >> a[i];
    }
    vector<long long> sum(100010);
    for (int k = 1; k <= n; ++k) {
        vector<int> b;
        for (int i = k - 1; i < n; i += k) {
            b.push_back(a[i]);
        }
        sum[k] = allgcd(b);
    }
    for (int i = 100010 - 1; i > 0; --i) {
        for (int j = i * 2; j < 100010; j += i) {
            sum[i] -= sum[j];
        }
    }
    long long res = 0;
    for (int i = 1; i < 100010; ++i) {
        res = (res + i * (sum[i] % M)) % M;
    }
    cout << res << '\n';

    return 0;
}