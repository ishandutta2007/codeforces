#include <bits/stdc++.h>

using namespace std;
int f[100001], n, k, db;
int holvan(int a) {
    if (f[a]==a) {
        return a;
    }
    int x=holvan(f[a]);
    f[a]=x;
    return x;
}
int unio(int a, int b)
{
    a=holvan(a);
    b=holvan(b);
    f[a]=b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        f[i]=i;
    }
    for (int i=1; i<=k; i++) {
        int a, b;
        cin >> a >> b;
        if (holvan(a)==holvan(b)) {
            db++;
        }
        unio(a, b);
    }
    cout << db << "\n";
    return 0;
}