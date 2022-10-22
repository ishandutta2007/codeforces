#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 2 * 1e18;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        vector<int> B, R;
        vector<int> C;
        int i, j, a;
        for(i=0;i<N;i++) {
            cin >> a;
            C.push_back(a);
        }
        string s;
        cin >> s;
        for(i=0;i<N;i++) {
            if(s[i] == 'B') B.push_back(C[i]);
            else R.push_back(C[i]);
        }
        sort(B.begin(),B.end());
        sort(R.begin(),R.end());
        reverse(R.begin(),R.end());
        bool isPos = true;
        for(i=0;i<R.size();i++) {
            if(R[i] > N - i) isPos = false;
        }
        for(i=0;i<B.size();i++) {
            if(B[i] < i+1) isPos = false;
        }
        if(isPos) cout << "YES\n";
        else cout << "NO\n";
    }
}