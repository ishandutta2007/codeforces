#include <bits/stdc++.h>

using namespace std;
int n;
string s, ans;
void solve() {
    cin >> n >> s;
    ans=s;
    for (int i=0; i<min(n, 100); i++) {
        string p=s;
        for (int j=0; j<n-i; j++) {
            if (s[j]=='1') {
                p[i+j]='1';
            }
        }
        //cout << "proba " << i << " " << p << endl;
        ans=max(ans, p);
    }
    bool jo=0;
    for (auto x:ans) {
        if (x=='1') jo=1;
        if (jo) {
            cout << x;
        }
    }
    if (!jo) {
        cout << 0;
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}