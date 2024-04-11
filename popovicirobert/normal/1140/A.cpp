#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    vector <int> arr(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;

    i = 1;
    while(i <= n) {
        int j = i, mx = arr[i];

        while(j <= n && mx >= j) {
            mx = max(mx, arr[j]);
            j++;
        }

        cnt++;
        i = j;
    }

    cout << cnt;

    //cin.close();
    //cout.close();
    return 0;
}