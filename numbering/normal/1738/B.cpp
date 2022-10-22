#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100005];
int B[100005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, j;
        int N;
        cin >> N;
        int k;
        cin >> k;
        for(i=0;i<k;i++) cin >> A[i];
        for(i=0;i+1<k;i++) B[i] = A[i+1] - A[i];
        bool isPos = true;
        for(i=0;i+1<k-1;i++) {
            if(B[i]>B[i+1]) isPos = false;
        }
        int a;
        if(k!=N) {
            int val = N-k+1;
            int s = A[0] + (N-k+1) * (1e9);
            a = s / (N-k+1);
            int rem = s % (N-k+1);
            a -= 1e9;
            if(rem>0) a++;
        }
        else a = A[0];
        if(k>=2&&a > B[0]) isPos = false;
        cout << (isPos ? "YES\n":"NO\n");
    }
}