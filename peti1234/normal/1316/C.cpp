#include <bits/stdc++.h>

using namespace std;
long long n, m, p, x=-1, y=-1;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> p;
    for (int i=0; i<n; i++) {
        int a; cin >> a;
        if (a%p && x==-1) x=i;
    }
    for (int i=0; i<m; i++) {
        int a; cin >> a;
        if (a%p && y==-1) y=i;
    }
    cout << x+y << "\n";
    return 0;
}