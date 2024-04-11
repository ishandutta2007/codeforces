#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[500005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i, j;
        int sum = 0;
        for(i=0;i<N;i++) {
            int a;
            cin >> a;
            sum += a-1;
        }
        if(sum%2==0) cout << "maomao90\n";
        else cout << "errorgorn\n";
    }
}