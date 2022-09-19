#include <bits/stdc++.h>

using namespace std;
const int c=3000005;
long long n, db[c], pref[c], m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        db[x]++;
    }
    for (int i=1; i<c; i++) {
        for (int j=1; i*j<c; j++) {
            if (i!=j) pref[i*j]+=db[i]*db[j];
            else pref[i*j]+=db[i]*(db[i]-1);
        }
    }
    for (int i=2; i<c; i++) {
        pref[i]+=pref[i-1];
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        cout << n*(n-1)-pref[x-1] << "\n";
    }
    return 0;
}