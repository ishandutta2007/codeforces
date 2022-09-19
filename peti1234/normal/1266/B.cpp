#include <bits/stdc++.h>

using namespace std;
int q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while(q--) {
        long long n;
        cin >> n;
        if (n<=14) {
            cout << "no" << "\n";
            continue;
        }
        n%=14;
        if (n>0 && n<=6) cout << "yes";
        else cout << "no";
        cout << "\n";
    }
    return 0;
}