#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 400000 + 2000;
const int md = 998244353;
const int md2 = 1e9 + 7;

// double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> ans;
void reverse(vector<int> &a, int p) {
    reverse(a.begin(), a.begin() + p);
    if (p) ans.push_back(p * 2);
    range(i, p) if (a[i] >= 2) a[i] ^= 1;
}

vector<int> get(string &a) {
    int n = (int)a.size() / 2;
    vector<int> a1(n);
    range(i, n) {
        auto s = a.substr(i * 2, 2);
        if (s == "00") {
            a1[i] = 0;
        } else if (s == "11") {
            a1[i] = 1;
        } else if (s == "01") {
            a1[i] = 3;
        } else {
            a1[i] = 2;
        }
    }
    return a1;
}

int check(vector<int> a, vector<int> &b) {
    int n = a.size();
    for(int i = n - 1; i >= 0; --i) {
        if (a[i] == b[i]) continue;
        if (b[i] == 0 || b[i] == 1) {
            range(j, i) if (a[j] == b[i]) {
                    reverse(a, j + 1);
                    break;
                }
            reverse(a, i + 1);
        } else {
            range(j, i) if (a[j] == b[i]) {
                    reverse(a, j + 1);
                    break;
                }
            if ((a[0] ^ 1) != b[i]) {
                range(j, i + 1) if ((a[j] ^ 1) == b[i]) {
                        reverse(a, j + 1);
                        break;
                    }
                reverse(a, 1);
            }
            reverse(a, i + 1);
        }
        if (a[i] != b[i]) {
            return -1;
        }
    }
    return ans.size();
}

int check(int mid, vector<int> a, vector<int> &b) {
    ans.clear();
    reverse(a, mid);
    return check(a, b);
}

void solve() {
    int n; cin >> n;
    ll s = 0;
    range(i, n) {
        int a; cin >> a;
        s += a;
    }
    cout << (s - 1) / n + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}