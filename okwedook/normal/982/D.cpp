#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

map<int, int> mapp;
set<int> myind;
vector<int> arr;
vector<pii> sorted; 

void add(int ind) {
    auto it = myind.upper_bound(ind);
    int first = -1, second = -1;
    first = *(it);
    --it;
    second = *(it);
    mapp[first - second]--;
    if (mapp[first - second] == 0) mapp.erase(first - second);
    myind.insert(ind);
    mapp[ind - second]++;
    mapp[first - ind]++;
    mapp.erase(1);
}

int main() {
    FAST;
    int n;
    cin >> n;
    myind.insert(-1);
    myind.insert(n);
    mapp[n + 1]++;
    arr = vector<int> (n);
    for (auto &i : arr) cin >> i;
    sorted = vector<pii>(n);
    for (int i = 0; i < n; ++i)
        sorted[i].f = arr[i], sorted[i].s = i;
    sort(sorted);
    reverse(sorted);
    ll ans = sorted[0].f + 1, cnt = 1;
    for (int i = 0; i < n;) {
        int curr = i;
        while (curr < n && sorted[curr].f == sorted[i].f)
            add(sorted[curr].s), ++curr;
        if (mapp.size() == 1) {
            auto it = mapp.begin();
            if (it->f > 1) {
                if (it->s > cnt || it->s == cnt && sorted[i].f < ans) {
                    cnt = it->s;
                    ans = curr < n ? sorted[curr].f + 1 : sorted[i].f;
                }
            }
        }
        i = curr;
    }
    cout << ans;
    return 0; 
}