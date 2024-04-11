#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 1009;
const double PI = acos(-1);

typedef complex<double> cmplx;

int n, m, k;
vector<long long> a[N];

namespace FFT {
    void fft(vector<cmplx> &a, int logN, int sign) {
        for (int i = 0; i < a.size(); i++) {
            int mask = 0;
            for (int j = 0; j < logN; j++) {
                if (i >> j & 1) mask |= (1 << logN - j - 1);
            }
            if (i < mask) swap(a[i], a[mask]);
        }

        for (int k = 1; k < a.size(); k <<= 1) {
            for (int i = 0; i < k; i++) {
                double theta = PI * i * sign / k;
                cmplx w = polar(1.0, theta);
                for (int j = i; j < a.size(); j += k * 2) {
                    cmplx foo = a[j];
                    cmplx bar = w * a[j + k];
                    a[j] = foo + bar;
                    a[j + k] = foo - bar;
                }
            }
        }
    }

    vector<long long> mult(vector<long long> &a, vector<long long> &b) {
        int sz = a.size() + b.size() - 1;
        int logN = 0;
        while ((1 << logN) < sz) logN++;
        vector<cmplx> aa(1 << logN, 0), bb(1 << logN, 0);
        for (int i = 0; i < a.size(); i++) aa[i] = a[i];
        for (int i = 0; i < b.size(); i++) bb[i] = b[i];
        fft(aa, logN, 1);
        fft(bb, logN, 1);
        for (int i = 0; i < aa.size(); i++) {
            aa[i] *= bb[i];
        }
        fft(aa, logN, -1);
        vector<long long> res(sz);
        for (int i = 0; i < sz; i++) {
            res[i] = (long long)(aa[i].real() / (1 << logN) + 0.5);
        }
        return res;
    }
};

vector<long long> solve(int l, int r) {
    if (l == r) return a[l];
    int m = l + r >> 1;
    vector<long long> p1 = solve(l, m);
    vector<long long> p2 = solve(m + 1, r);
    vector<long long> res = FFT::mult(p1, p2);
    if (res.size() > k) res.resize(k + 1);
    for (long long &u : res) u %= MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        a[i].push_back(1);
    }
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        a[u].push_back(1);
    }
    vector<long long> res = solve(1, m);
    cout << res[k] << endl;
    return 0;
}