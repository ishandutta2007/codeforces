#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>
#include <math.h>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()
using namespace std;

int inp[200001];
int outp[200001];

bool comp(int &a, int &b) {
    if (inp[a] + outp[a] != inp[b] + outp[b]) return inp[a] + outp[a] < inp[b] + outp[b];
    return a < b;
}

void solve() {
    int n; cin >> n;
    vector<int> w(n, 0);
    for(int i = 1; i <= n; ++i) {
        w[i - 1] = i;
        int f;
        cin >> f;
        if (f) {
            inp[i] = f;
            outp[f] = i;
        }
    }
    sort(all(w), comp);
    deque<int> s;
    range(_, 2) {
        for(auto i: w) {
            if (!s.empty() && !outp[i]) {
                outp[i] = s.front();
                inp[s.front()] = i;
                s.pop_front();
            }
            if (!inp[i]) {
                s.push_back(i);
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << inp[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}