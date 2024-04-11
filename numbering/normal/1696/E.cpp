#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p = 1e9 + 7;
int fac[500005];
int inv[500005];
int power(int a, int b, int c) {
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0) {
        int k = power(a, b/2, c);
        return k * k % c;
    }
    else {
        return power(a, b-1, c) * a % c;
    }
}
int nCr(int n, int r) {
    if(r>n||r<0) return 0;
    int k = fac[n] * inv[r] % p;
    k = k * inv[n-r] % p;
    return k;
}
int A[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int i, j;
    fac[0] = 1;
    for(i=1;i<=500003;i++) fac[i] = fac[i-1] * i % p;
    inv[500003] = power(fac[500003], p-2, p);
    for(i=500002;i>=0;i--) inv[i] = inv[i+1] * (i+1) % p;
    for(i=0;i<=N;i++) cin >> A[i];
    if(A[0]==0) {
        cout << "0";
        return 0;
    }
    A[N+1] = 0;
    int ans = p-1;
    for(i=0;i<=N;i++) {
        if(A[i]==0) break;
        if(A[i]!=A[i+1]) ans += (nCr(A[i]+i,i+1) - nCr(A[i+1]+i,i+1)+p)%p;
        ans %= p;
        ans = (ans + nCr(A[i]-1+i,i)) % p;
        //cout << ans << '\n';
    }
    cout << ans;
}