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
#include <queue>

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
#define hashmap unordered_map
#define hashset unordered_set
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

void ex() {
    cout << "NO";
    exit(0);
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<pair<string, string>> arr(n);
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        arr[i].f = s1.substr(0, 3);
        arr[i].s = s1.substr(0, 2) + s2[0];
    }
    auto brr = arr;
    sort(brr);
    for (int i = 1; i < n; ++i) 
        if (brr[i] == brr[i - 1]) ex();
    map<string, set<int>> st;
    for (int i = 0; i < n; ++i) st[arr[i].f].insert(i), st[arr[i].s].insert(i);
    vector<string> answer(n);
    for (int i = 0; i < n; ++i) {
        if (sz(st[arr[i].s]) == 1) answer[i] = arr[i].s;
        else if (sz(st[arr[i].f]) == 1) answer[i] = arr[i].f;
    }
    map<string, int> cnt;
    for (auto i : arr) cnt[i.f]++;
    set<string> used, usedfirst;
    for (int i = 0; i < n; ++i) 
        if (sz(answer[i]) == 0) {
            --cnt[arr[i].f];
            if (!used.count(arr[i].s)) answer[i] = arr[i].s;
            else if (!used.count(arr[i].f)) answer[i] = arr[i].f;
            //if (cnt[answer[i]]) ex();
            ++cnt[arr[i].f];
            //if (usedfirst.count(answer[i])) ex();
            used.insert(answer[i]);
            usedfirst.insert(arr[i].f);
        }
    for (auto i : answer)
        if (sz(i) == 0) ex();
    cout << "YES\n";
    for (auto i : answer) cout << i << '\n';
    return 0;
}