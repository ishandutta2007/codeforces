#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

vector <int> arr, mxl, mxr;
vector <int> where;

ll divide(int l, int r) {
    if(l == r) {
        return 0;
    }

    int mid = (l + r) / 2, i;
    ll ans = 0;

    mxl[mid + 1] = mxr[mid] = 0;

    for(i = mid; i >= l; i--) {
        mxl[i] = max(mxl[i + 1], arr[i]);
    }
    for(i = mid + 1; i <= r; i++) {
        mxr[i] = max(mxr[i - 1], arr[i]);
    }

    for(i = mid; i >= l; i--) {
        int pos = where[mxl[i] - arr[i]];
        if(mxr[pos] <= mxl[i] && pos > mid && pos <= r) {
            ans++;
        }
    }
    for(i = mid + 1; i <= r; i++) {
        int pos = where[mxr[i] - arr[i]];
        if(mxl[pos] <= mxr[i] && pos >= l && pos <= mid) {
            ans++;
        }
    }

    ans += divide(l, mid) + divide(mid + 1, r);

    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    arr.resize(n + 2), where.resize(n + 2);
    mxl.resize(n + 2), mxr.resize(n + 2);

    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        where[arr[i]] = i;
    }

    cout << divide(1, n);

    //cin.close();
    //cout.close();
    return 0;
}