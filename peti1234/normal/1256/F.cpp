#include <bits/stdc++.h>

using namespace std;
int w, n, db;
string a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        db=0;
        if (n<26) {
            for (int i=0; i<n; i++) {
                for (int j=i+1; j<n; j++) {
                    if (a[i]>a[j]) {
                        db++;
                    }
                    if (b[i]>b[j]) {
                        db++;
                    }
                }
            }
        }
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        for (int i=1; i<n; i++) {
            if (a[i]==a[i-1]) {
                db=0;
            }
        }
        cout << (db%2==0 && a==b ? "YES" : "NO") << "\n";
    }
    return 0;
}