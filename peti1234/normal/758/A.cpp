#include <bits/stdc++.h>

using namespace std;
int n;
int t[101];
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    int maxi=0;
    for (int i=1; i<=n; i++) {
        if (t[i]>maxi) {
            maxi=t[i];
        }
    }
    int os=0;
    for (int i=1; i<=n; i++) {
        os+=maxi-t[i];
    }
    cout << os << endl;
    return 0;
}