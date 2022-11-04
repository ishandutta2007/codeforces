#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 5e5;

int arr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    if(n == 1) {
        cout << arr[1];
        return 0;
    }
    sort(arr + 1, arr + n + 1);
    ll sum = 0;
    int cnt1 = 0, cnt2 = 0;
    for(i = 1; i <= n; i++) {
        sum += abs(arr[i]);
        if(arr[i] < 0) {
            cnt1++;
        }
        else {
            cnt2++;
        }
    }
    if(cnt1 && cnt2) {
        cout << sum;
        return 0;
    }
    if(cnt1) {
        cout << sum - 2 * abs(arr[n]);
    }
    if(cnt2) {
        cout << sum - 2 * abs(arr[1]);
    }
    //cin.close();
    //cout.close();
    return 0;
}