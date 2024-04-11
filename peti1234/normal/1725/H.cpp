#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, t[c], db[3];
int main()
{
    ios_base::sync_with_stdio(false);
    /*for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << ((i+j)*(i+j)+i*j)%3 << " ";
        }
        cout << "\n";
    }*/
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        db[t[i]%3]++;
    }
    if (2*db[0]>n) {
        cout << 2 << "\n";
        int s=0;
        for (int i=1; i<=n; i++) {
            int x=t[i]%3;
            if (x==0 && s<n/2) {
                cout << 0;
                s++;
            } else {
                cout << 1;
            }
        }
        cout << "\n";
    } else {
        cout << 0 << "\n";
        int s=0;
        for (int i=1; i<=n; i++) {
            int x=t[i]%3;
            if (x==0) cout << 0;
            else if (db[0]+s<n/2) {
                cout << 0;
                s++;
            } else {
                cout << 1;
            }
        }
        cout << "\n";
    }
    return 0;
}