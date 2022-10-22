#include <bits/stdc++.h>
#define int long long
using namespace std;
int A[200005];
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
        string s;
        cin >> s;
        vector<int> i1, i2;
        for(i=0;i<N;i++) {
            if(s[i]=='0') i1.push_back(A[i]);
            else i2.push_back(A[i]);
        }
        sort(i1.begin(),i1.end());
        sort(i2.begin(),i2.end());
        int sz = i1.size();
        for(i=0;i<N;i++) {
            if(s[i]=='0') {
                cout << 1 + (lower_bound(i1.begin(),i1.end(),A[i])- i1.begin()) << ' ';
            }
            else {
                cout << 1 + sz + (lower_bound(i2.begin(),i2.end(),A[i])-i2.begin()) << ' ';
            }
        }
        cout << '\n';
    }
}