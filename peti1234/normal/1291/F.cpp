#include <bits/stdc++.h>

using namespace std;
int n, k, x, pos, db;
bool v[1032];
int main()
{
    cin >> n >> k, x=n/k;
    if (k==1) x/=2;
    for (int i=0; i<x; i++) {
        pos=i;
        for (int i=0; i<n/k; i++) {
            if (i%2) pos-=i;
            else pos+=i;
            if (pos<0) pos+=n/k;
            if (pos>=n/k) pos-=n/k;
            for (int j=pos*k+1; j<=pos*k+k; j++) if (!v[j]) {
                cout.flush() << "? " << j << "\n";
                char c;
                cin >> c;
                if (c=='Y') v[j]=1;
            }
        }
        cout.flush() << "R" << "\n";
    }
    for (int i=1; i<=n; i++) db+=!v[i];
    cout << "! " << db << "\n";
}