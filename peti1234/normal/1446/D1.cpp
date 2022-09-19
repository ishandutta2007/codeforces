#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int t[c], db[c], n, pos, maxi;
int esz[c], hsz[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        db[t[i]]++;
    }
    for (int i=1; i<=n; i++) {
        if (db[t[i]]>db[pos]) pos=t[i];
    }
    for (int i=1; i<=n; i++) {
        if (i!=pos && db[i]) {
            int cnt=0, emax=0, hmax=0, dif=db[pos]-db[i];
            for (int j=1; j<=n; j++) {
                if (t[j]==pos) cnt++;
                if (t[j]==i) cnt--;
                if (cnt>emax) {
                    emax++;
                    esz[emax]=j;
                }
            }
            cnt=0;
            for (int j=n; j>=1; j--) {
                if (t[j]==pos) cnt++;
                if (t[j]==i) cnt--;
                if (cnt>hmax) {
                    hmax++;
                    hsz[hmax]=n-j+1;
                }
            }
            for (int j=0; j<=dif; j++) {
                if (j<=emax && dif-j<=hmax) {
                    maxi=max(maxi, n-esz[j]-hsz[dif-j]);
                }
            }
        }
    }
    cout << maxi << "\n";
    return 0;
}