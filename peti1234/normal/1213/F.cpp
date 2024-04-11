#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int db[c], a[c], b[c], inv[c], n, k, cnt;
char x='a';
string sol;
void add(int p) {
    db[p]++;
    if (db[p]%2) cnt++;
    else cnt--;
}
int main()
{
    cin >> n >> k, k--;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        inv[a[i]]=i;
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }
    for (int i=1; i<=n; i++) {
        sol+=x;
        add(a[i]), add(b[i]);
        if (!cnt && k) {
            x++;
            if (i!=n) k--;
        }
    }
    if (k) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i=1; i<=n; i++) {
            cout << sol[inv[i]-1];
        }
        cout << "\n";
    }
    return 0;
}