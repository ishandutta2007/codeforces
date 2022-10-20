#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 5050;

int n, m, res;
int c[N], used[N], cnt[110];

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        cnt[c[i]]++;
    }
    sort(c , c + n);
    int lmax = *max_element(cnt + 1, cnt + m + 1);
    if(lmax * 2 > n) res = (n - lmax) * 2;
    else res = n;
    cout << res << endl;
    for(int i = 0; i < n; i++)
        cout << c[i] << " " << c[(i + lmax) % n] << endl;
    return 0;
}