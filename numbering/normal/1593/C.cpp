#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        int k;
        cin >> N >> k;
        vector<int> X;
        int a;
        int i;
        for(i=0;i<k;i++) {
            cin >> a;
            X.push_back(N-a);
        }
        sort(X.begin(),X.end());
        int pt = 0;
        int sum = 0;
        while(pt < X.size() && sum <= N-1) {
            sum += X[pt];
            pt++;
        }
        //cout << sum << ' ';
        if(sum >= N) cout << pt - 1 << '\n';
        else cout << k << '\n';
    }
}