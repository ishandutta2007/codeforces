#include <bits/stdc++.h>

using namespace std;

const int c=200005;
long long n, m, mod, ksum, nsum, ans, t[c], t2[c], cnt[c], cnt2[c], amod=1e9+7;
long long s(long long ert) {
    return (ert%mod+mod)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> mod;

    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        ksum=(ksum+x)%mod;
        cnt[ksum]++;
        t[i]=ksum;
    }
    if (!ksum) {
        for (int i=0; i<mod; i++) {
            cnt2[i]=cnt[i]*m;
        }
    } else {
        long long ert=0;
        for (int i=1; i<=m; i++) {
            ert+=cnt[s(-ksum*i)];
        }
        for (int i=0; i<mod; i++) {
            long long uj=s(ksum*i), regi=s(ksum*(i-m));
            ert+=cnt[uj];
            ert-=cnt[regi];
            cnt2[uj]=ert;

        }
    }
    nsum=ksum*m%mod;
    for (int i=0; i<mod; i++) {
        cnt2[i]%=amod;
    }
    if (!nsum) {
        for (int i=0; i<mod; i++) {
            ans+=cnt2[i]*(cnt2[i]-1)%amod;
        }
        ans++;
        cout << ans%amod << "\n";
        return 0;
    }

    for (int i=0; i<mod; i++) {
        ans+=cnt2[i]*(cnt2[i]-1)/2%amod;
    }
    for (int i=1; i<=n; i++) {
        t2[t[i]]++;
        ans+=m*t2[s(t[i]-nsum)]%amod;
    }


    long long ert=0, dif=0;
    for (int i=0; i<m-1; i++) {
        long long p=s(-nsum+i*ksum);
        dif+=cnt[p];
        ert+=cnt[p]*(m-i-1);
        ert%=amod;
    }
    for (int i=0; i<mod; i++) {
        long long pos=s(i*ksum), uj=s(pos-nsum+(m-1)*ksum), regi=s(pos-nsum);
        dif-=cnt[regi], dif+=cnt[uj];
        ert+=dif;
        ert-=cnt[regi]*(m-1);
        ert%=amod;
        ans+=cnt[pos]*ert%amod;
    }
    cout << ans%amod << "\n";
    return 0;
}