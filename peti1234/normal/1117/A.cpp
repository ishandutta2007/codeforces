#include <bits/stdc++.h>

using namespace std;
int maxi=0;
int t[100001];
int n;
long long s, a;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        maxi=max(maxi, t[i]);
    }
    for (int i=1; i<=n; i++) {
        if (t[i]==maxi) {
            a++;
            s=max(s, a);
        } else {
            a=0;
        }
    }
    cout << s << endl;
    return 0;
}