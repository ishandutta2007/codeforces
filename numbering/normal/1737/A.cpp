#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[30];
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, k;
        cin >> N >> k;
        string s;
        cin >> s;
        int i, j;
        for(i=0;i<30;i++) A[i] = 0;
        for(i=0;i<N;i++) A[s[i]-'a']++;
        for(i=0;i<k;i++) {
            int d = N / k;
            int pt = 0;
            while(pt<d&&A[pt]>0) {
                A[pt]--;
                pt++;
            }
            cout << (char)('a'+pt);
        }
        cout << '\n';
    }
}