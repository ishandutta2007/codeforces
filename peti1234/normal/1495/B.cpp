#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, t[c], bal[c], jobb[c], maxi, cnt, pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=2; i<=n; i++) {
        if (t[i]>t[i-1]) {
            bal[i]=bal[i-1]+1;
            maxi=max(maxi, bal[i]);
        }
    }
    for (int i=n-1; i>=1; i--) {
        if (t[i]>t[i+1]) {
            jobb[i]=jobb[i+1]+1;
            maxi=max(maxi, jobb[i]);
        }
    }
    for (int i=1; i<=n; i++) {
        if (bal[i]==maxi && jobb[i]==maxi) {
            cnt++;
            pos=i;
        }
    }
    bool jo=(cnt==1);
    if (maxi%2) {
        jo=0;
    }
    for (int i=1; i<=n; i++) {
        if (i!=pos) {
            if (bal[i]==maxi) {
                jo=0;
            }
            if (jobb[i]==maxi) {
                jo=0;
            }
        }
    }
    cout << jo << "\n";
    return 0;
}