#include <bits/stdc++.h>

using namespace std;
int n, db, p, q;
int main()
{
    cin >> n;
    while(db<n) {
        p+=5, q=p;
        while(q%5==0) q/=5, db++;
    }
    if (db==n) {
        cout << 5 << "\n";
        for (int i=p; i<p+5; i++) cout << i << " ";
        cout << "\n";
    }
    else cout << 0 << "\n";
    return 0;
}