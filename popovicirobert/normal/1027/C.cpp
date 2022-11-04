#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;

int arr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, n, i;
    ios::sync_with_stdio(false);
    cin >> t;
    while(t > 0) {
        t--;
        cin >> n;
        for(i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        sort(arr + 1, arr + n + 1);
        pair <int, int> sol;
        double ans = 1e18;
        int pos = 1;
        i = 1;
        while(i <= n) {
            if(i < n && arr[i] == arr[i + 1]) {
                pos = max(pos, i + 2);
                while(pos < n && arr[pos] < arr[pos + 1]) {
                    pos++;
                }
                if(pos >= n) {
                    break;
                }
                if(ans > 1.0 * (arr[i] + arr[pos]) * (arr[i] + arr[pos]) / (1.0 * arr[i] * arr[pos])) {
                    ans = 1.0 * (arr[i] + arr[pos]) * (arr[i] + arr[pos]) / (1.0 * arr[i] * arr[pos]);
                    sol = {arr[i], arr[pos]};
                }
            }
            i++;
        }
        cout << sol.first << " " << sol.first << " " << sol.second << " " << sol.second << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}