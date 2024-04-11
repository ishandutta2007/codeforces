#include <bits/stdc++.h>

using namespace std;
int n;
int o, e;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        if (a==1) {
            o++;
        } else {
            e++;
        }
    }
    if (e>0) {
        cout << 2 << " ";
    }
    e--;
    if (o>0) {
        cout << 1 << " ";
    }
    o--;
    for (int i=1; i<=e; i++) {
        cout << 2 << " ";
    }
    for (int i=1; i<=o; i++) {
        cout << 1 << " ";
    }
    return 0;
}