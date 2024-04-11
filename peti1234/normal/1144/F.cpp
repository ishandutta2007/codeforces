#include <bits/stdc++.h>

using namespace std;
const int c=400005;
int n, m, ki[c], bal[c], jobb[c];
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> bal[i] >> jobb[i];
        unio(bal[i], jobb[i]+n);
        unio(jobb[i], bal[i]+n);
    }
    for (int i=1; i<=n; i++) {
        if (holvan(i)==holvan(i+n)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i=1; i<=m; i++) {
        cout << (holvan(bal[i])==holvan(1));
    }
    cout << "\n";
    return 0;
}