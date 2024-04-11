#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));

    int mid = (n - 1) / 2;
    int ptr1 = mid, ptr2 = n - 1;

    int ans = n;

    while (ptr2 > mid and ptr1 >= 0) {
        while (ptr1 > 0 and a[ptr1] > a[ptr2] / 2)
            ptr1 -= 1;
        if (ptr1 == 0 and a[ptr1] > a[ptr2] / 2)
            break;
        ans -= 1;
        ptr2 -= 1;
        ptr1 -= 1;
    }

    cout << ans << " ";
    return 0;

}