#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;
int arr[300001];

void solve2(int n) {
    range(i, n) {
        cin >> arr[i];
    }
    ll a = 0, b = 0;
    range(i, n) {
        if (i%2) {
            a += arr[i] / 2;
            b += arr[i] - arr[i] / 2;
        } else {
            a += arr[i] - arr[i] / 2;
            b += arr[i] / 2;
        }
    }
    cout << min(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    tests = 1;
    //cin >> tests;
    range(_, tests) {
        int n; cin >> n;
        solve2(n);
    }
    return 0;
}