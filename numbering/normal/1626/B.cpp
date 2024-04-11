#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int A[10];
int B[200005];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int i, j;
        for(i=0;i<10;i++) A[i] = INF;
        int N = s.length();
        reverse(s.begin(),s.end());
        bool isDone = false;
        for(i=0;i<N;i++) B[i] = s[i] - '0';
        for(i=0;i<N-1;i++) {
            if(B[i]+B[i+1] >= 10) {
                int m = B[i] + B[i+1];
                int m1 = m / 10;
                int m2 = m % 10;
                s[i+1] = m1 + '0';
                s[i] = m2 + '0';
                isDone = true;
                break;
            }
        }
        if(isDone) {
            for(i=N-1;i>=0;i--) cout << s[i];
            cout << '\n';
            continue;
        }
        for(i=N-2;i>=0;i--) {
            if(i==N-2) cout << (char)('0'+B[i]+B[i+1]);
            else cout << s[i];
        }
        cout << '\n';
    }
}