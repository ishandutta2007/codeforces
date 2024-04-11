#include <bits/stdc++.h>
#define int long long
using namespace std;
int p;
struct SegTree {
    vector<bool> seg;
    int MAX;
    void init(int N) {
        int i;
        for(i=1;i<2*N;i*=2) {}
        seg.resize(i);
        MAX = i;
        fill(seg.begin(),seg.end(),true);
    }
    void cons() {
        for(int i = MAX/2-1;i>=1;i--) {
            seg[i] = seg[2*i] && seg[2*i+1];
        }
    }
    void update(int n) {
        n += MAX/2;
        n /= 2;
        while(n) {
            seg[n] = seg[2*n] && seg[2*n+1];
            n /= 2;
        }
    }
    void update(int a, bool k) {
        seg[a+MAX/2] = k;
        update(a);
    }
};
struct Ma {
    int a11, a12;
    int a21, a22;
    Ma(int a,int b, int c, int d) :a11(a),a12(b),a21(c),a22(d) {}
    Ma():a11(0),a12(0),a21(0),a22(0){}
};
Ma mul(Ma a, Ma b) {
    Ma c;
    c.a11 = (a.a11*b.a11+a.a12*b.a21) % p;
    c.a12 = (a.a11*b.a12+a.a12*b.a22) % p;
    c.a21 = (a.a21*b.a11+a.a22*b.a21) % p;
    c.a22 = (a.a21*b.a12+a.a22*b.a22) % p;
    return c;
}
int fibo[300005];
void cons() {
    Ma k = Ma(1,0,0,1);
    for(int i = 0; i <= 300000; i++) {
        fibo[i] = k.a12;
        k = mul(k, Ma(1,1,1,0));
    }
}
int A[300005];
int B[300005];
int C[300005];
int D[300005];
SegTree tree;
bool check(int N) {
    if(N==1) return A[0]==B[0];
    if(N==2) return A[0]==B[0]&&A[1]==B[1];
    if(A[0]!=B[0]||A[1]!=B[1]) return false;
    return tree.seg[1];
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, Q;
    cin >> N >> Q >> p;
    cons();
    int i;
    for(i=0;i<N;i++) cin >>A[i];
    for(i=0;i<N;i++) cin >>B[i];
    for(i=0;i+2<N;i++) {
        C[i] = (A[i]+A[i+1]-A[i+2]+p)%p;
        D[i] = (B[i]+B[i+1]-B[i+2]+p)%p;
    }
    tree.init(N+5);
    for(i=0;i+2<N;i++) {
        if(C[i]!=D[i]) tree.update(i, false);
    }
    for(i=0;i<Q;i++) {
        char c;
        int l, r;
        cin >>c >> l >> r;
        if(l==1) {
            if(c=='A') {
                A[0] += 1;
                A[0] %= p;
            }
            else {
                B[0] += 1;
                B[0] %= p;
            }
            if(r>=2) {
                if(c=='A') {
                    A[1] += 1;
                    A[1] %= p;
                }
                else {
                    B[1] += 1;
                    B[1] %= p;
                }
            }
        }
        if(l==2) {
            if(c=='A') {
                A[1] += 1;
                A[1] %= p;
            }
            else {
                B[1] += 1;
                B[1] %= p;
            }
        }
        l--;
        r--;
        if(l-2>=0) {
            if(c=='A') {
                C[l-2] += p - 1;
                C[l-2] %= p;
            }
            else {
                D[l-2] += p - 1;
                D[l-2] %= p;
            }
            tree.update(l-2, C[l-2]==D[l-2]);
        }
        int f1 = fibo[r-l];
        int f2 = fibo[r-l+1];
        if(r-1>=0&&r-1<N-2) {
            if(c=='A') {
                C[r-1] += f1+f2;
                C[r-1] %= p;
            }
            else {
                D[r-1] += f1+f2;
                D[r-1] %= p;
            }
            tree.update(r-1, C[r-1]==D[r-1]);
        }
        if(r<N-2) {
            if(c=='A') {
                C[r] += f2;
                C[r] %= p;
            }
            else {
                D[r] += f2;
                D[r] %= p;
            }
            tree.update(r, C[r]==D[r]);
        }
        if(check(N)) cout << "YES\n";
        else cout << "NO\n";
    }
}