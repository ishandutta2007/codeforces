#include <bits/stdc++.h>
#define int long long
using namespace std;
int query(int i, int j, int k) {
    cout << "? " << i << ' ' <<j << ' ' <<k << endl;
    int a;
    cin >> a;
    return a;
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int v1 = query(1, 2, 3);
        int v2 = query(1, 2, 4);
        int v3 = query(1, 3, 4);
        int v4 = query(2, 3, 4);
        int ma = max(max(v1, v2),max(v3, v4));
        int a, b, d;
        if(ma==v1) {
            if(ma==v2) a=1, b=2, d=3;
            if(ma==v3) a=1, b=3, d=2;
            if(ma==v4) a=2, b=3, d=1;
        }
        if(ma==v2) {
            if(ma==v3) a=1, b=4, d=2;
            if(ma==v4) a=2, b=4, d=1;
        }
        if(ma==v3&&ma==v4) a=3, b=4, d=1;
        for(int i=5;i<=n;i++) {
            int v = query(a, d, i);
            int v2 = query(b, d, i);
            if(v<=ma&&v2<=ma) continue;
            ma = max(ma, v);
            ma = max(ma, v2);
            if(v>v2) {
                b = i;
            }
            else a = i;
        }
        cout << "! " << a << ' ' << b << endl;
    }
}