#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[500005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int i, j;
        int N, K;
        cin >> N >> K;
        for(i=0;i<N;i++) cin >> A[i];
        set<int> S;
        for(i=0;i<N;i++) S.insert(A[i]);
        bool isPos = false;
        for(i=0;i<N;i++) {
            if(S.find(A[i]-K)!=S.end()) isPos = true;
        }
        cout << (isPos ? "YES\n" : "NO\n");
    }
}