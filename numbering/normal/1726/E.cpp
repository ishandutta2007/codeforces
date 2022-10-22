#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int fac[300005];
int inv[300005];
int isum_o[300005];
int isum_e[300005];
int power(int a, int b, int c) {
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==1) {
        return power(a, b-1, c) * a % c;
    }
    if(b%2==0) {
        int k = power(a, b/2, c);
        return k * k % c;
    }
}
int A[300005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i, j;
    fac[0] = 1;
    for(i=1;i<=300003;i++) {
        fac[i] = (fac[i-1] * i) % p;
    }
    inv[300003] = power(fac[300003], p-2, p);
    for(i=300002;i>=0;i--) {
        inv[i] = (inv[i+1] * (i+1)) % p;
    }
    for(i=1;i<=300003;i+=2) {
        isum_o[i] = ((i >= 3 ? isum_o[i-2]:0) + inv[i]) % p;
    }
    for(i=0;i<=300003;i+=2) {
        isum_e[i] = ((i >= 2 ? isum_e[i-2]:0) + inv[i]) % p;
    }
    A[0] = 1;
    A[1] = 1;
    A[2] = 2;
    for(i=3;i<=300003;i++) {
        A[i] = (i-1) * A[i-2] % p;
        A[i] = (A[i] + A[i-1]) % p;
    }
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int ans = 0;
        int cnt2 = 1;
        for(int k = 0; k <= N-k; k+=2) {
            int cnt1 = fac[N-k] * inv[k] % p;
            cnt1 = (cnt1 * inv[N-2*k])%p;
            cnt1 = (cnt1 * cnt2) % p;
            cnt1 = (cnt1 * A[N-2*k]) % p;
            ans = (ans + cnt1) % p;
            cnt2 = (cnt2 * 2 ) % p;
            cnt2 = (cnt2 * (k+1)) % p;
            //cout << k << " : " << cnt1 << ' ' << cnt2 << '\n';
        }
        cout << ans << '\n';
    }
}