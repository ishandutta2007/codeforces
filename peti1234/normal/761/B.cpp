#include <bits/stdc++.h>

using namespace std;
int n, h, p;
int t[51];
int l[51];
void ell()
{
    sort (t+1, t+n+1);
    sort (l+1, l+n+1);
    for (int i=1; i<=n; i++) {
        if (t[i]!=l[i]) {
            return;
        }
    }
    p++;
}
int main()
{
    cin >> n >> h;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> l[i];
    }
    for (int i=1; i<=n; i++) {
        if (l[i]==0) {
            l[i]=h;
        }
    }
    for (int j=1; j<=h; j++) {
        for (int i=1; i<=n; i++) {
            if (t[i]==h) {
            t[i]=1;
        }
        else {
                t[i]++;
        }
        }
        ell();

    }
    if (p==0) {
    cout << "NO"<< endl;
    return 0;
    } else {
    cout << "YES";
    }
    return 0;
}