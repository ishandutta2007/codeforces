#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

int arr[100001];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    int ans = 0, pos = 1;
    for(i = 1; i <= n; i++) {
        while(pos <= n && arr[i] >= arr[pos]) {
            pos++;
        }
        if(pos <= n) {
            pos++;
            ans++;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}