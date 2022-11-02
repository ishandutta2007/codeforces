#include<bits/stdc++.h>

using namespace std;
//#define int long long

const int inf = 1e9;
int f[30][1500001];
bool used[52];
int n;
int a[52];
int main() {
    cin >> n;
    for(int i = 0;i < 2 * n;i++) cin >> a[i];
    sort(a, a + 2 * n);
    int sum = 0;
    for(int i = 2;i < 2 * n;i++) sum += a[i];

    f[0][0] = 1;
    for(int i = 2;i < 2 * n;i++) {
        for(int j = sum / 2;j >= 0;j--) {
            for(int cnt = n;cnt >= 0;cnt--) {
                if (f[cnt][j] == 0) continue;
                if (f[cnt + 1][j + a[i]] != 0) continue;
                f[cnt + 1][j + a[i]] = i;
            }
        }
    }

    int id1 = inf;
    int id2 = n - 1;
    for(int i = sum;i>= 0; i--) {
        if (f[id2][i] != 0 && abs(id1 - sum / 2) > abs(i - sum / 2)) {
            id1 = i;
        }
    }

    while(id2 >= 0) {
        used[f[id2][id1]] = true;
        id1 -= a[f[id2][id1]];
        id2--;
    }

    for(int i = 0;i < 2 * n;i++) if (used[i]) cout << a[i] << " ";
    cout << '\n';
    for(int i = 2 * n - 1;i >= 0;i--) if (!used[i]) cout << a[i] << " ";
}