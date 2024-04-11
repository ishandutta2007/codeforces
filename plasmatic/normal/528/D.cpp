// ./d-fuzzy-search.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
template <typename T> vector<T> multiply(vector<T> const& a, vector<T> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<T> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int mp(char c) {
    switch (c) {
        case 'A': return 0;
        case 'T': return 1;
        case 'G': return 2;
        default: return 3;
    }
}

const int MN = 2e5+1;
int N, M, K,
    cnt[MN];
string s, t;
vector<int> idx[4], tidx[4];
bool ok[MN][4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K >> s >> t;
    for (auto i = 0; i < 4; i++) idx[i].push_back(-INF);
    for (auto i = 0; i < N; i++) idx[mp(s[i])].push_back(i);
    for (auto i = 0; i < 4; i++) idx[i].push_back(INF);
    for (auto i = 0; i < M; i++) tidx[mp(t[i])].push_back(i);

    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < 4; j++) {
            auto nxt = lower_bound(idx[j].begin(), idx[j].end(), i), pre = nxt-1;
            ok[i][j] = min(*nxt-i, i-*pre) <= K;
        }
    }

    for (auto i = 0; i < 4; i++) {
        vector<int> A(N), B(N+1);
        for (auto j = 0; j < N; j++) {
            if (ok[j][i])
                A[j] = 1;
        }
        for (auto j : tidx[i])
            B[N-j] = 1;

        auto res = multiply(A, B);
        for (auto j = N; j < (int)res.size(); j++)
            if (res[j])
                cnt[j-N] += res[j];
    }

    int ans = 0;
    for (auto i = 0; i < N; i++) ans += cnt[i] == M;
    cout << ans << '\n';

    return 0;
}