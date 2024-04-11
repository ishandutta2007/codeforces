#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int p[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    pair<int, int> maxVal(0, 1);

    int ll = 1;
    while (ll < n && p[ll + 1] < p[ll]) ll++;
    if (maxVal.first < ll - 1) {
        maxVal = {ll - 1, 1};
    } else if (maxVal.first == ll - 1) {
        maxVal.second++;
    }

    int rr = n;
    while (rr > 1 && p[rr - 1] < p[rr]) rr--;
    if (maxVal.first < n - rr) {
        maxVal = {n - rr, 1};
    } else if (maxVal.first == n - rr) {
        maxVal.second++;
    }


    for (int i = 2; i < n; i++) {
        if (p[i] > p[i - 1] && p[i] > p[i + 1]) {
            int l = i - 1;
            while (l > 1 && p[l - 1] < p[l]) l--;
            int r = i + 1;
            while (r < n && p[r + 1] < p[r]) r++;
            int left = i - l;
            int right = r - i;
            int val = max(left, right);
            if (maxVal.first < val) {
                maxVal = {val, 1};
            } else if (maxVal.first == val) {
                maxVal.second++;
            }
        }
    }
    if (maxVal.second > 1) {
        cout << 0 << '\n';
        return 0;
    }
    int res = 0;
    for (int i = 2; i < n; i++) {
        if (p[i] > p[i - 1] && p[i] > p[i + 1]) {
            int l = i - 1;
            while (l > 1 && p[l - 1] < p[l]) l--;
            int r = i + 1;
            while (r < n && p[r + 1] < p[r]) r++;
            int left = i - l;
            int right = r - i;
            if (left == right && left > 0 && left % 2 == 0 && left == maxVal.first) res++;
        }
    }
    cout << res << '\n';
    return 0;
}