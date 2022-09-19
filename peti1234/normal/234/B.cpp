#include <bits/stdc++.h>

using namespace std;
int n, k, ert, t[1002], db[102], pos;
int main()
{
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    cin >> n >> k;
    ert=k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        db[t[i]]++;
    }
    for (int i=100; i>=1; i--) {
        ert-=db[i];
        if (ert<=0) {
            pos=i;
            break;
        }
    }
    cout << pos << "\n";
    for (int i=1; i<=n; i++) {
        if (k && t[i]>=pos) {
            cout << i << " ";
            k--;
        }
    }
    cout << "\n";
    return 0;
}