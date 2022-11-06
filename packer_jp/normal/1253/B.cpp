#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define all(x) (x).begin(), (x).end()
#define uniq(x) (x).erase(unique(all(x)), (x).end())
#define bit(n) (1LL << (n))
#define dump(x) cerr << #x " = " << (x) << endl
using vint=vector<int>;
using vvint=vector<vint>;
using pint=pair<int, int>;
using vpint=vector<pint>;
template<typename T> using priority_queue_rev=priority_queue<T, vector<T>, greater<T>>;
constexpr double pi = 3.1415926535897932384626433832795028;
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int gcd(int a, int b) {
    while (b) { swap(a %= b, b); }
    return a;
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<typename T1, typename T2> bool chmax(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T1, typename T2> bool chmin(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &rhs) {
    os << "(" << rhs.first << ", " << rhs.second << ")";
    return os;
}
template<typename T> ostream &operator<<(ostream &os, const vector<T> &rhs) {
    os << "{";
    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {
        os << *itr << (next(itr) != rhs.end() ? ", " : "");
    }
    os << "}";
    return os;
}
struct setup {
    static constexpr int PREC = 20;
    setup() {
        cout << fixed << setprecision(PREC);
        cerr << fixed << setprecision(PREC);
    };
} setup;

int n;
int a[110000];
void invalid() {
    cout << -1 << endl;
    exit(0);
}
signed main() {
    cin >> n;
    rep(i, n) { cin >> a[i]; }
    int cnt = 0, day = 0, last = -1;
    vint ans;
    vector<bool> is_in(1100000);
    vint is_already(1100000, -1);
    rep(i, n) {
        day++;
        if (a[i] > 0) {
            if (is_already[a[i]] > last) { invalid(); }
            is_in[a[i]] = true;
            is_already[a[i]] = i;
            cnt++;
        } else {
            a[i] = -a[i];
            if (!is_in[a[i]]) { invalid(); }
            is_in[a[i]] = false;
            cnt--;
            if (cnt == 0) {
                ans.push_back(day);
                day = 0;
                last = i;
            }
        }
    }
    if (cnt > 0) { invalid(); }
    cout << ans.size() << endl;
    rep(i, ans.size()) { cout << ans[i] << " "; }
    cout << endl;

}