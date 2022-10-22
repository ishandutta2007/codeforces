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
        int N;
        cin >> N;
        for(i=0;i<N;i++) cin >> A[i];
        bool is1 = false, is2 = false;
        for(i=0;i<N;i++) {
            if(A[i]==0) is1 = true;
            if(A[i]==1) is2 = true;
        }
        if(is1&&is2) cout << "NO\n";
        else if(!is2) cout << "YES\n";
        else {
            sort(A, A+N);
            bool isPos = true;
            for(i=0;i+1<N;i++) {
                if(A[i]+1==A[i+1]) isPos = false;
            }
            cout << (isPos ? "YES\n" : "NO\n");
        }
    }
}