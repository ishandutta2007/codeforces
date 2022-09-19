#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
long long mod=998244353, n, fakt[c], inv[c], ans, cnt, db;
bool v[c];
priority_queue<pair<int, int> > q;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<0 || a<b || b<0) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    fakt[0]=1;
    for (int i=1; i<c; i++) {
        fakt[i]=fakt[i-1]*i%mod;
    }
    inv[c-1]=oszt(fakt[c-1]);
    for (int i=c-2; i>=0; i--) {
        inv[i]=inv[i+1]*(i+1)%mod;
    }

    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        q.push({-x, i});
    }
    while (cnt<n) {
        auto s=q.top();
        q.pop();
        int fi=s.first, ert=-fi-db, id=s.second;
        //cout << "ertek " << ert << " " << id << "\n";
        if (ert<0) {
            break;
        }
        ans+=alatt(n+ert-1, ert);
        ans%=mod;
        //ans+=alatt(n-1, 0)+alatt(n, 1)+alatt(n+1, 2).....+alatt(n+ert-1, ert);
        if (!v[id]) {
            v[id]=1;
            cnt++;
        } else {
            int rem=n-cnt;
            ans=(ans+mod-alatt(n+ert-rem-1, ert-rem))%mod;
            //cout << "fontos " << rem << " " << n+ert-1 << " " << ert-rem << "\n";
        }
        q.push({fi-n, id});
        db++;
        //cout << "vege " << ans << "\n";
    }

    cout << ans << "\n";
    return 0;
}
/*
3
0 1 2
*/