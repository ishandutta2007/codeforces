#include <bits/stdc++.h>
#define int long long
const int INF = 1e18;
using namespace std;
int power(int a,int b, int c) {
    a %= c;
    if(b==0) return 1;
    if(b==1) return a;
    if(a==0) return 0;
    if(a==1) return 1;
    if(b%2==0) {
        int k = power(a, b/2, c);
        return k * k % c;
    }
    if(b%2==1) {
        int k = power(a, b-1, c);
        return k * a % c;
    }
}
int L[5005];
int R[5005];
int fac[5005];
int inv[5005];
const int p = 998244353;
int A[5005];
int B[5005];
int nCr(int n, int r) {
    int cnt = fac[n] * inv[r] % p;
    cnt = cnt * inv[n-r] % p;
    return cnt;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    int N, k;
    cin >> N >> k;
    int i, j;
    string s;
    cin >> s;
    fac[0] = 1;
    for(i=1;i<=5000;i++) {
        fac[i] = fac[i-1] * i % p;
    }
    inv[5000] = power(fac[5000],p-2,p);
    for(i=4999;i>=0;i--) {
        inv[i] = inv[i+1] * (i + 1) % p;
    }
    for(i=0;i<N;i++) {
        if(!i) A[i] = s[i] == '1' ? 1 : 0;
        else A[i] = A[i-1] + (s[i] == '1' ? 1 : 0);
    }
    j = 0;
    int ans = 1;
    for(i=0;i<N;i++) {
        while(j+1<N&&A[j+1]-(i ? A[i-1] : 0)<=k) j++;
        //cout << j << '\n';
        if(A[j]-(i ? A[i-1] : 0) != k) break;
        B[i+1] = j;
        ans += nCr(j-i+1,k);
        if(i && s[i-1] == '0' && B[i]-i+1 >= 0) ans += p - nCr(B[i]-i+1,k);
        else if(i && s[i-1] == '1' && B[i]-i+1>=0) ans += p - nCr(B[i]-i+1,k-1);
        else ans += p - 1;
        ans %= p;
        //cout << i << ' ' << j << ' ' << ans << '\n';
    }
    cout << ans;
}