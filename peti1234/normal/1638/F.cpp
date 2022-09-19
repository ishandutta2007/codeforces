#include <bits/stdc++.h>

using namespace std;
const int c=10005;
long long n, t[c], ans, maxi[c], pref[c], suf[c], ert[c], ert2[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<=n; i++) {
        pref[i]=pref[i-1];
        long long val=t[i];
        for (int j=i; j>=1; j--) {
            val=min(val, t[j]);
            pref[i]=max(pref[i], val*(i-j+1));
        }
    }
    for (int i=n; i>=1; i--) {
        suf[i]=suf[i+1];
        long long val=t[i];
        for (int j=i; j<=n; j++) {
            val=min(val, t[j]);
            suf[i]=max(suf[i], val*(j-i+1));
        }

    }
    for (int i=0; i<=n; i++) {
        ans=max(ans, pref[i]+suf[i+1]);
    }
    for (int i=1; i<=n; i++) {
        long long val=t[i];
        for (int j=i; j<=n; j++) {
            val=min(val, t[j]);
            maxi[j-i+1]=max(maxi[j-i+1], val);
        }
    }
    for (int i=1; i<=n; i++) {
        long long cnt=0, maxdb=0, t2=0;
        for (int j=1; j<=n; j++) {
            if (t[j]>=t[i]) cnt++;
            else cnt=0;
            maxdb=max(maxdb, cnt);
        }

        for (int j=1; j<=n; j++) {
            t2=max(t2, j*(maxi[j]-t[i]));
        }
        ans=max(ans, maxdb*t[i]+t2);
    }
    for (int fix=2; fix<n; fix++) {
        int l=fix, r=fix;
        while (t[l-1]>=t[fix]) l--;
        while (t[r+1]>=t[fix]) r++;
        memset(ert, 0, sizeof(ert)), memset(ert2, 0, sizeof(ert2));
        ert[l]=ert[r]=t[fix];
        for (int i=l-1; i>=1; i--) ert[i]=min(ert[i+1], t[i]);
        for (int i=r+1; i<=n; i++) ert[i]=min(ert[i-1], t[i]);

        ert2[1]=r*ert[1], ert2[n]=(n-l+1)*ert[n];
        for (int i=2; i<=l; i++) ert2[i]=max((r-i+1)*ert[i], ert2[i-1]);
        for (int i=n-1; i>=r; i--) ert2[i]=max((i-l+1)*ert[i], ert2[i+1]);


        int pos=n;
        for (int i=l; i>=1; i--) {
            while (ert[pos]+ert[i]<t[fix]) pos--;
            ans=max({ans, (r-i+1)*ert[i]+(pos-l+1)*(t[fix]-ert[i]), (r-i+1)*(t[fix]-ert[pos])+(pos-l+1)*ert[pos]});
        }

        pos=r;
        for (int i=1; i<=l; i++) {
            while (ert[i]+ert[pos]>t[fix]) pos++;
            ans=max(ans, ert2[i]+ert2[pos]);
        }
    }
    cout << ans << "\n";
    return 0;
}