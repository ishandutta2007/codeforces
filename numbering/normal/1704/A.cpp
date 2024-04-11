#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, M;
        cin >> N >> M;
        string a, b;
        cin >> a >> b;
        bool isPos = true;
        int i;
        for(i=M-1;i>=1;i--) {
            if(b[i]!=a[N-M+i]) isPos = false;
        }
        int cnt1 = 0, cnt2= 0;
        for(i=0;i<=N-M;i++) {
            if(a[i]=='0') cnt1++;
            if(a[i]=='1') cnt2++;
        }
        if(b[0]=='1'&&cnt2==0) isPos = false;
        if(b[0]=='0'&&cnt1==0) isPos = false;
        cout << (isPos ? "YES\n": "NO\n");
    }
}