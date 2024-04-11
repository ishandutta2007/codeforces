#include <bits/stdc++.h>

using namespace std;
const int c=105;
int n, t[c], ki[c];
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
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (i>x) unio(i-x, i);
        if (i+x<=n) unio(i, i+x);
    }
    for (int i=1; i<=n; i++) {
        if (holvan(i)!=holvan(t[i])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}