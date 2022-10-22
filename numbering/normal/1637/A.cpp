#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[100005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i;
        for(i=0;i<N;i++) cin >> A[i];
        bool isPos = true;
        for(i=0;i+1<N;i++) {
            if(A[i]>A[i+1]) isPos = false;
        }
        cout << (!isPos ? "YES\n" : "NO\n");
    }
}