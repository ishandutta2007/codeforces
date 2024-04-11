#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int A[100005];
int B[100005];
int D[100005];
int C[100005];
int pow2[100005];
int fac[100005];
int inv[100005];
int power(int a, int b, int c) {
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0) {
        int k = power(a, b/2, c);
        return k*k%c;
    }
    else {
        return a*power(a, b-1, c) % c;
    }
}
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
    cin >> t;
    pow2[0] = 1;
    for(int i = 1; i <= 100003; i++) {
        pow2[i] = pow2[i-1] * 2 % p;
    }
    fac[0] = 1;
    for(int i=1;i<=100003;i++) fac[i] = fac[i-1] * i % p;
    inv[100003] = power(fac[100003], p-2, p);
    for(int i=100002;i>=0;i--) {
        inv[i] = inv[i+1] * (i+1) % p;
    }
    while(t--) {
        int N;
        cin >> N;
        int i, j;
        for(i=0;i<N;i++) cin >> A[i];
        for(i=0;i<N;i++) B[i] = C[i] = D[i] = 0;
        if(N==1) {
            cout << 1 << '\n';
            continue;
        }
        if(N==2) {
            cout << (A[0]==A[1]?2:1) << '\n';
            continue;
        }
        int cnt = 0;
        bool AllZero = true;
        for(i=0;i<N;i++) {
            if(A[i]!=0) AllZero = false;
        }
        if(AllZero) {
            cout << pow2[N-1] << '\n';
            continue;
        }
        int st = 0, en = N-1;
        while(A[st]==0) st++;
        while(A[en]==0) en--;
        int cnt1 = st;
        int cnt2 = N-1 - en;
        int res = nCr(cnt1+cnt2+2, cnt1+1);
        for(i=st;i<=en;) {
            B[cnt] = A[i];
            i++;
            while(i<=en&&A[i]==0) {
                C[cnt]++;
                i++;
            }
            cnt++;
        }
        N = cnt;
        D[0] = B[0];
        for(i=1;i<N;i++) {
            D[i] = D[i-1] + B[i];
        }
        int sum = D[N-1];
        map<int,int> M;
        for(i=0;i<N;i++) {
            M[D[i]] = i;
        }
        vector<array<int, 2>> V1, V2;
        for(i=-1;i<N;i++) {
            if(i==-1) {
                V1.push_back({-1, N-1});
                V2.push_back({cnt1, cnt2});
                continue;
            }
            if(D[i] > sum - D[i]) break;
            if(M.count(sum - D[i])) {
                int e = M[sum - D[i]];
                V1.push_back({i, e});
                V2.push_back({C[i], C[e]});
            }
        }
        int ans = 1;
        for(i=V1.size()-1;i>=0;i--) {
            if(i==V1.size()-1) {
                if(V1[i][0]==V1[i][1]) {
                    int s = V2[i][0];
                    ans = pow2[s+1];
                    continue;
                }
                else ans = 1;
            }
            if(i!=0) ans = ans * nCr(V2[i][0]+V2[i][1]+2, V2[i][0]+1) % p;
            else ans = ans * nCr(V2[i][0]+V2[i][1], V2[i][0]) %p;
            //cout << V1[i][0] << ' ' << V1[i][1] << " : " <<V2[i][0] << ' ' << V2[i][1] << '\n';
            //cout << ans << '\n';
        }
        //cout << "Ans : ";
        cout << ans << '\n';
    }
}