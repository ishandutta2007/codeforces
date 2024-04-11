#include <bits/stdc++.h>

using namespace std;
int n, k;
int os;
int t[101];
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    int a=0;
    while (k>0 && a<n) {
        a++;
        os+=t[a];
        k-=min({8, k, os});
        os-=min({8, k, os});
    }
    if (k>0) {
        cout << -1 << endl;
    } else {
    cout << a << endl;
    }
    return 0;
}