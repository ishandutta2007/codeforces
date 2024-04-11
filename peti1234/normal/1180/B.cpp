#include <bits/stdc++.h>

using namespace std;
int n, t[100005], pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        if (t[i]>=0) {
            t[i]=-t[i]-1;
        }
        if (t[i]<t[pos]) {
            pos=i;
        }
    }
    if (n%2) {
        t[pos]=-t[pos]-1;
    }
    for (int i=1; i<=n; i++) {
        cout << t[i] << " ";
    }
    cout << "\n";
    return 0;
}