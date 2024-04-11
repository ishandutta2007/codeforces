#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long w, n, t[c], pref[c], maxi[c], sok=1e10;
bool jo[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            pref[i]=pref[i-1]+t[i];
        }
        for (int i=1; i<=n+1; i++) {
            maxi[i]=sok;
        }
        for (int len=1; len<=n+1; len++) {
            for (int kezd=n-len+1; kezd>=1; kezd--) {
                if (pref[kezd+len-1]-pref[kezd-1]<maxi[kezd+len]) {
                    jo[kezd]=1;
                }
            }
            maxi[n+1]=0;
            bool spec=0;
            for (int i=1; i<=n; i++) {
                maxi[i]=(jo[i] ? pref[i+len-1]-pref[i-1] : 0);
                if (jo[i]) {
                    spec=1;
                }
                jo[i]=0;
            }
            for (int i=n; i>=1; i--) {
                maxi[i]=max(maxi[i+1], maxi[i]);
            }
            if (!spec) {
                //cout << "valasz ";
                cout << len-1 << "\n";
                break;
            }
        }

        for (int i=0; i<=n+1; i++) {
            t[i]=0, pref[i]=0, maxi[i]=0, jo[i]=0;
        }
    }
    return 0;
}
/*
1
5
9 6 7 9 7
*/