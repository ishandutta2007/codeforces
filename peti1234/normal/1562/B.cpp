#include <bits/stdc++.h>

using namespace std;
bool pr[1002];
int n, w, t[1002];
string s;
void solve() {
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        t[i]=s[i]-'0';
    }
    for (int i=0; i<n; i++) {
        if (pr[t[i]]) {
            cout << 1 << "\n" << t[i] << "\n";
            return;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int x=10*t[i]+t[j];
            if (pr[x]) {
                cout << 2 << "\n" << x << "\n";
                return;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int x=10*t[i]+t[j];
            for (int k=j+1; k<n; k++) {
                int y=10*x+t[k];
                if (pr[y]) {
                    cout << 3 << "\n" << y << "\n";
                    return;
                }
            }
        }
    }
}
int main()
{
    pr[1]=1;
    for (int i=2; i<=1000; i++) {
        for (int j=2; j<i; j++) {
            if (i%j==0) {
                pr[i]=1;
            }
        }
    }
    cin >> w;
    while (w--) {
        solve();
        for (int i=0; i<n; i++) {
            if (!pr[s[i]]) {

            }
        }
    }
    return 0;
}