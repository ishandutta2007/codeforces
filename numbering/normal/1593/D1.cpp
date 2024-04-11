#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if(a < b) swap(a, b);
    while(b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        vector<int> A;
        int a;
        int i;
        cin >> N;
        for(i=0;i<N;i++) {
            cin >> a;
            A.push_back(a);
        }
        sort(A.begin(),A.end());
        int ans = 0;
        for(i=0;i<A.size()-1;i++) {
            ans = gcd(ans, A[i+1] - A[i]);
        }
        if(ans == 0) cout << "-1\n";
        else cout << ans << '\n';
    }
}