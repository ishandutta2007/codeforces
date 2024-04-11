#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

struct RollingHash {
    unsigned long long int mod61 = (1LL << 61) - 1;
    unsigned long long int Mul61(unsigned long long int a, unsigned long long int b) {
        unsigned long long int au = a >> 31;
        unsigned long long int ad = a ^ (au << 31);
        unsigned long long int bu = b >> 31;
        unsigned long long int bd = b ^ (bu << 31);
        unsigned long long int ret = au * bu * 2;
        ret += ad * bd;
        unsigned long long int mid = ad * bu + au * bd;
        unsigned long long int midu = mid >> 30;
        unsigned long long int midd = mid & ((1 << 30) - 1);
        ret += midu + (midd << 31);
        return ret;
    }
    unsigned long long int CalcMod61(unsigned long long int num) {
        return num % mod61;
    }
    int num;
    vector<unsigned long long int>h;
    vector<unsigned long long int>by;
    RollingHash(string s, unsigned int base = 10007) {
        num = s.size();
        h.resize(s.size() + 1);
        by.resize(s.size() + 1, 1);
        for (int i = 1; i <= num; i++) {
            by[i] = CalcMod61(Mul61(by[i - 1], base));
            h[i] = CalcMod61(Mul61(h[i - 1], base) + s[i-1]);
        }
    }
    unsigned long long int Get(int l, int r) {
        return CalcMod61(h[r] + mod61 * 4 - Mul61(h[l], by[r - l]));
    }
};

void nx(string& s) {
    s.back()++;
    for (int i = s.size() - 1; i > 0; i--) {
        if (s[i] == '2') {
            s[i] = '0';
            s[i - 1]++;
        }
        else break;
    }
    return;
}

void Solve() {
    cin >> N >> K;
    set<unsigned long long int>st;
    string s;
    cin >> s;
    for (auto& i : s) {
        if (i == '0')i = '1';
        else i = '0';
    }
    RollingHash rh(s);
    for (int i = 0; i + K <= N; i++) {
        st.insert(rh.Get(i, i + K));
    }
    string t(K, '0');
    while (t[0] < '2') {
        RollingHash rh2(t);
        if (st.find(rh2.Get(0, K)) == st.end()) {
            cout << "YES\n";
            cout << t << endl;
            return;
        }
        nx(t);
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
}