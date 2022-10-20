#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010;

int n, q;
int a[N], next[N];
map<int, long long> M;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], next[i] = i + 1;
    for(int i = n; i; i--) {
        int tr = i;
        for(int j = i; j <= n; j = next[j]) {
            a[j] = __gcd(a[j], a[tr]);
            M[a[j]] += 1ll * (next[j] - j);
            if(a[j] == a[tr])
                next[tr] = next[j];
            tr = j;
        }
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        cout << M[x] << endl;
    }
    return 0;
}