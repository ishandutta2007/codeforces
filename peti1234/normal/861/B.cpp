#include <bits/stdc++.h>

using namespace std;
int n, m;
int t[101];
int k[101];
bool jo(int a)
{
    for (int i=1; i<=m; i++) {
        if ((t[i]-1)/a+1!=k[i]) {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        cin >> t[i] >> k[i];
    }
    int h=-1;
    for (int i=1; i<=100; i++) {
        if (jo(i)) {
            if (h==-1) {
                h=(n-1)/i+1;
            }
            if (h!=(n-1)/i+1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << h << endl;
    return 0;
}