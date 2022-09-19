#include <bits/stdc++.h>

using namespace std;
int n, db, pos=1, k, x, t[105];
int main()
{
    cin >> n >> k;
    db=n;
    for (int i=1; i<=k; i++) {
        cin >> x;
        x%=db;
        while (x || t[pos]) {
            if (!t[pos]) x--;
            pos++;
            if (pos>n) pos=1;
        }
        cout << pos << " ";
        t[pos]=1;
        while (t[pos]) {
            pos++;
            if (pos==n+1) pos=1;
        }
        db--;
    }
    return 0;
}