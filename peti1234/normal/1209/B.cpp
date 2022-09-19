#include <bits/stdc++.h>

using namespace std;
const int c=102;
bool v[c];
int n, maxi, a[c], b[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        if (c=='1') {
            v[i]=true;
        }
    }
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i=1; i<=5000; i++) {
        int db=0;
        for (int i=1; i<=n; i++) {
            db+=v[i];
        }
        maxi=max(maxi, db);
        for (int j=1; j<=n; j++) {
            if (i>=b[j] && ((i-b[j])%a[j])==0) {
                v[j]=!v[j];
            }
        }
    }
    cout << maxi << "\n";
    return 0;
}