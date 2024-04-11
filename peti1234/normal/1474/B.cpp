#include <bits/stdc++.h>

using namespace std;
const int c=100002;
bool pr[c];
int w, n, x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=2; i<c; i++) {
        if (!pr[i]) {
            for (int j=2*i; j<c; j+=i) {
                pr[j]=1;
            }
        }
    }
    cin >> w;
    while (w--) {
        cin >> n;
        for (x=n+1; ; x++) {
            if (!pr[x]) {
                break;
            }
        }
        for (y=x+n; ; y++) {
            if (!pr[y]) {
                break;
            }
        }
        cout << x*y << "\n";
    }
    return 0;
}