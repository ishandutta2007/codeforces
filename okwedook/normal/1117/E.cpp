#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <tuple>
#include <random>
#include <bitset>

using namespace std;

#define FIXED cout << fixed << setprecision(15)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RANDOM srand(85453532)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 1000000007
#define inf 4000000000000000007ll
#define f first
#define s second
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { 
    if (y < x) return x = y, true;
    return false; 
}
template<class T, class U> inline bool ifmax(T &x, U y) { 
    if (y > x) return x = y, true;
    return false; 
}
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) { 
    for (auto &i : a) stream >> i;
    return stream;
}

mt19937_64 gen(25546232352ll);

int rand(int a, int b) {
    uniform_int_distribution<int> uni(a, b);
    return uni(gen);
}

string generate(int n) {
    string ans = "";
    for (int i = 0; i < n; ++i) ans += char(rand('a', 'z'));
    return ans;
}

vector<pii> changes;

string ask(string s) {
    //for (auto i : changes) swap(s[i.f], s[i.s]);
    //return s;
    cout << "? " << s << endl;
    string ans;
    cin >> ans;
    return ans;
}

signed main() {
    FAST; FIXED; RANDOM;
    string t;
    cin >> t;
    /*int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        changes.pb({a, b});
    }*/
    int n = sz(t);
    string s1(n, '0');
    string s2(n, '0');
    string s3(n, '0');
    string s = "";
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            for (int k = 0; k < 26; ++k) {
                s += char('a' + i);
                s += char('a' + j);
                s += char('a' + k);
            }
    for (int i = 0; i < n; ++i) s1[i] = s[3 * i];
    for (int i = 0; i < n; ++i) s2[i] = s[3 * i + 1];
    for (int i = 0; i < n; ++i) s3[i] = s[3 * i + 2];
    string ans1 = ask(s1);
    string ans2 = ask(s2);
    string ans3 = ask(s3);
    //cout << s1 << ' ' << ans1 << '\n';
    //cout << s2 << ' ' << ans2 << '\n';
    //cout << s3 << ' ' << ans3 << '\n';
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        if (s1[i] != ans1[i]) used[i] = true;
        if (s2[i] != ans2[i]) used[i] = true;
        if (s3[i] != ans3[i]) used[i] = true;
    }
    string answer = t;
    for (int i = 0; i < n; ++i) 
        if (used[i]) {
            for (int j = 0; j < n; ++j) 
                if (used[j]) {
                    if (ans1[j] == s1[i] && ans2[j] == s2[i] && ans3[j] == s3[i]) {
                        answer[i] = t[j];
                        break;
                    }
                }
        }
    cout << "! " << answer << endl;
    return 0;
}