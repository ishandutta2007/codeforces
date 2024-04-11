#include <bits/stdc++.h>

using namespace std;
int n, t[100001], db;
long long kul;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    t[0]=-1;
    for (int i=1; i<=n; i++) {
        kul+=t[i]-i+1;
        if (i>1) {
            if (t[i]==t[i-1]) {
                db++;
                if (t[i-2]+1==t[i]) {
                    db++;
                }
            }
        }
    }
    if (db>1 || kul%2==0) {
        cout << "cslnb";
    } else {
        cout << "sjfnb";
    }
    return 0;
}