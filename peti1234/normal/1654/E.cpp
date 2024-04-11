#include <bits/stdc++.h>

using namespace std;
const int c=100005, gy=400, sok=4e7;
int n, t[c], maxi, s[2*sok];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    maxi=min(n, 2);
    for (int p=1; p<=2; p++) {
        for (int dif=0; dif<=gy; dif++) {
            for (int i=1; i<=n; i++) {
                int h=t[i]-i*dif+sok;

                s[h]++;
                maxi=max(maxi, s[h]);
            }
            for (int i=1; i<=n; i++) {
                int h=t[i]-i*dif+sok;
                s[h]--;
            }
        }

        for (int kezd=1; kezd<=n; kezd++) {
            for (int i=kezd+1; i<=min(n, kezd+gy); i++) {
                if (t[i]>t[kezd] && (t[i]-t[kezd])%(i-kezd)==0) {
                    int h=(t[i]-t[kezd])/(i-kezd);
                    s[h]++;
                    maxi=max(maxi, s[h]+1);
                }
            }
            for (int i=kezd+1; i<=min(n, kezd+gy); i++) {
                if (t[i]>t[kezd] && (t[i]-t[kezd])%(i-kezd)==0) {
                    int h=(t[i]-t[kezd])/(i-kezd);
                    s[h]--;
                }
            }
        }

        reverse(t+1, t+n+1);
    }

    cout << n-maxi << "\n";
    return 0;
}