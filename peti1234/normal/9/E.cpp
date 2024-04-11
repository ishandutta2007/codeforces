#include <bits/stdc++.h>

using namespace std;
int n, m, db[100], ki[100];
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    } else {
        if (m<n) {
            cout << "NO\n";
            exit(0);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        db[a]++, db[b]++;
        unio(a, b);
    }
    for (int i=1; i<=n; i++) {
        if (db[i]>2) {
            cout << "NO\n";
            return 0;
        }
    }
    if (n==m) {
        for (int i=1; i<=n; i++) {
            if (holvan(i)!=holvan(1)) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n" << n-m << "\n";
    for (int i=1; i<=n-m; i++) {
        for (int kezd=1; kezd<=n; kezd++) {
            if (db[kezd]<2) {
                db[kezd]++;
                for (int veg=1; veg<=n; veg++) {
                    if (db[veg]<2 && (holvan(kezd)!=holvan(veg) || i==n-m)) {
                        db[veg]++;
                        cout << kezd << " " << veg << "\n";
                        if (i<n-m) unio(kezd, veg);
                        break;
                    }
                }
                break;
            }
        }
    }
    return 0;
}