#include <bits/stdc++.h>

using namespace std;
const int c=200003, gy=200;
long long ans;
int n, t[c], kov[c], pref[c], f[c*gy], el;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s, n=s.size();
    for (int i=1; i<=n; i++) {
        if (s[i-1]=='1') {
            t[i]=1;
        }
        pref[i]=pref[i-1]+t[i];
        if (t[i]) {
            for (int j=el+1; j<=i; j++) {
                kov[j]=i;
            }
            el=i;
        }
    }
    for (int i=el+1; i<=n+1; i++) {
        kov[i]=n+1;
    }
    /*
    for (int i=1; i<=n; i++) {
        cout << i << " " << kov[i] << endl;
    }
    */
    for (int i=1; i<=n; i++) {
        int cnt=1;
        for (int j=kov[i]; j<=n && cnt<n/gy; j=kov[j+1], cnt++) {
            int hossz=j-i+1, minh=max(hossz, cnt*(gy+1))-1, maxh=hossz+kov[j+1]-j-1;
            //cout << i << " " << j << " " << cnt << " " << minh << " " << maxh << endl;
            ans+=max(0, maxh/cnt-minh/cnt);
        }
    }
    //cout << ans << "\n";
    for (int i=1; i<=gy; i++) {
        f[n]=1;
        for (int j=1; j<=n; j++) {
            int ert=n+pref[j]*i-j;
            ans+=f[ert], f[ert]++;
        }
        for (int j=1; j<=n; j++) {
            int ert=n+pref[j]*i-j;
            f[ert]--;
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
00001100000000000000
*/