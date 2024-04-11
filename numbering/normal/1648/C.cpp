#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int power(int a, int b, int c) {
    a %= c;
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0) {
        int k = power(a, b/2, c);
        return k * k % c;
    }
    if(b%2==1) {
        int k = power(a, b-1, c);
        return k * a % c;
    }
}
int fac[200005];
int inv[200005];
struct SegTree {
    vector<int> seg;
    int MAX;
    SegTree(int N) {
        int i;
        for(i=1;i<2*N;i*=2) {}
        seg.resize(i);
        MAX = i;
    }
    void cons() {
        for(int i=MAX/2-1;i>=1;i--) {
            seg[i] = seg[2*i] + seg[2*i+1];
        }
    }
    void update(int n) {
        n += MAX/2;
        n /= 2;
        while(n) {
            seg[n] = seg[2*n] + seg[2*n+1];
            n/=2;
        }
    }
    void Edit(int n, int a) {
        seg[n+MAX/2] += a;
        update(n);
    }
    int sum(int s, int e, int n, int ns, int ne) {
        if(e<=ns||ne<=s) return 0;
        if(s<=ns&&ne<=e) return seg[n];
        int mid = ns + ne >> 1;
        return sum(s,e,2*n,ns,mid)+sum(s,e,2*n+1,mid,ne);
    }
    int sum(int s, int e) {
        return sum(s,e,1,0,MAX/2);
    }
};
int A[200005];
int B[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    int i;
    for(i=0;i<N;i++) {
        int a;
        cin >> a;
        A[a]++;
    }
    for(i=0;i<M;i++) cin >> B[i];
    fac[0] = 1;
    for(i=1;i<=200003;i++) fac[i] = fac[i-1] * i % p;
    inv[200003] = power(fac[200003],p-2,p);
    //cout << power(2, 3, p) << '\n';
    for(i=200002;i>=0;i--) {
        inv[i] = inv[i+1] * (i+1) % p;
    }
    int ans = 0;
    SegTree tree(200005);
    int MAX = tree.MAX;
    for(i=1;i<=200000;i++) {
        tree.seg[i+MAX/2] = A[i];
    }
    tree.cons();
    int cnt = fac[N];
    for(i=1;i<=200000;i++) cnt = cnt * inv[A[i]] % p;
    //cout << cnt << '\n';
    for(i=0;i<min(M, N);i++) {
        int m = tree.sum(1, B[i]);
        //cout << m << ' ';
        int k = power(N-i, p-2, p);
        //cout << cnt << ' ';
        m = m * k % p;
        m = m * cnt % p;
        ans = (ans + m) % p;
        if(A[B[i]]==0) break;
        tree.Edit(B[i], -1);
        cnt = cnt * A[B[i]] % p;
        cnt = cnt * k % p;
        A[B[i]]--;
        //cout << ans << '\n';
    }
    if(i==N&&N!=M) ans++;
    ans %= p;
    cout << ans;
}