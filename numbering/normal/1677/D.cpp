#include <bits/stdc++.h>
#define int long long
using namespace std;
int fac[1000005];
int inv[1000005];
const int p = 998244353;
int A[1000005];
int B[1000005];
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
int naive(int N, int k) {
    vector<int> V(N);
    int i, j;
    for(i=0;i<N;i++) V[i] = i+1;
    int cnt2 = 0;
    do {
        vector<int> V2 = V;
        for(i=0;i<k;i++) {
            for(j=0;j<N-1;j++) {
                if(V2[j]>V2[j+1]) swap(V2[j],V2[j+1]);
            }
        }
        bool isPos = true;
        for(i=0;i<N;i++) {
            int cnt = 0;
            for(j=0;j<i;j++) {
                if(V2[j]>V2[i]) cnt++;
            }
            if(A[i]!=-1&&A[i]!=cnt) isPos = false;
        }
        if(isPos) {
            cnt2++;
            for(j=0;j<N;j++) cout << V[j] << ' ';
            cout << '\n';
            for(j=0;j<N;j++)cout << V2[j] <<' ';
            cout << "\n\n";
        }
    }while(next_permutation(V.begin(),V.end()));
    return cnt2;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fac[0] = 1;
    for(int i = 1; i <= 1000003;i++) {
        fac[i] = fac[i-1] * i % p;
    }
    inv[1000003] = power(fac[1000003],p-2,p);
    for(int i = 1000002;i>=0;i--) {
        inv[i] = inv[i+1] * (i+1) % p;
    }
    int t;
    cin >> t;
    while(t--) {
        int N, k;
        cin >> N >> k;
        bool isWrong = false;
        int i;
        for(i=0;i<N;i++) cin >> A[i];
        for(i=N-k;i<N;i++) {
            if(A[i]!= 0 && A[i] != -1) isWrong = true;
        }
        if(isWrong) {
            cout << "0\n";
            continue;
        }
        int ans = fac[N];
        for(i=0;i<N-k;i++) {
            if(A[i]==-1) continue;
            int cnt = power(i+1+k,p-2,p);
            ans = ans * cnt % p;
            if(A[i]==0) ans = ans * (k+1) % p;
        }
        cout << ans << '\n';
        //cout << "Naive : " << naive(N, k) << '\n';
    }
}