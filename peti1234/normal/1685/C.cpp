#include <bits/stdc++.h>

using namespace std;
int w, n, t[200005];
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        n*=2;
        int cnt=0, kezd=0, veg=0;
        cin >> s;
        for (int i=1; i<=n; i++) {
            if (s[i-1]=='(') cnt++;
            else cnt--;
            t[i]=cnt;
            if (cnt<0) {
                if (!kezd) kezd=i;
                veg=i;
            }
        }
        if (!kezd) {
            cout << 0 << "\n";
            continue;
        }
        if (kezd==veg) {
            cout << 1 << "\n";
            cout << kezd << " " << kezd+1 << "\n";
            continue;
        }
        int kpos=0, kert=0, vpos=n, vert=0, kmaxi=-1;
        for (int i=1; i<=n; i++) {
            cnt=t[i];
            if (i<kezd && cnt>kert) {
                kert=cnt;
                kpos=i;
            }
            if (kezd<=i && i<=veg) {
                kmaxi=max(kmaxi, cnt);
            }
            if (i>=veg && cnt>vert) {
                vert=cnt;
                vpos=i;
            }
        }
        if (kert+vert>=kmaxi) {
            cout << 1 << "\n";
            cout << kpos+1 << " " << vpos << "\n";
            continue;
        }
        cout << 2 << "\n";
        int maxi=0, maxpos=0;
        for (int i=1; i<=n; i++) {
            cnt=t[i];
            if (cnt>maxi) {
                maxi=cnt;
                maxpos=i;
            }
        }
        cout << 1 << " " << maxpos << "\n";
        cout << maxpos+1 << " " << n << "\n";
    }
    return 0;
}