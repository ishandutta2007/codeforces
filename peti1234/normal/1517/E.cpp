#include <bits/stdc++.h>

using namespace std;
const int c=300002;
long long mod=998244353;
long long w, n, t[c], kom[c], skom[c], sum, s2, ans;
void solve(long long ert) {
    //cout << "solve " << ert << "\n";
    // ossz[p]-ossz[s]>ert
    // szigoruan nagyobb!!
    for (int kezd=2; kezd<n-1; kezd++) {
        // ? sok c kezd-ig kezdtol felvaltva cp veg-ig onnantol p utana ?
        int lo=kezd-1, hi=n, mid;
        if (hi%2 == kezd%2) {
            hi++;
        }
        //cout << "ertekek " << kezd << " " << lo << " " << hi << "\n";
        while (hi-lo>2) {
            mid=(hi+lo)/2;
            if (mid%2 == kezd%2) {
                mid++;
            }

            long long val=skom[n-1]-skom[mid-1]+kom[mid-2]-kom[kezd-1];
            if (2*(val+ert)>sum) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        ans+=((lo+1-kezd)/2);
    }
}
long long trivi() {
    long long cnt=0;
    for (int i=0; i<(1<<n); i++) {
        vector<int> cc, pp;
        int s1=0, s2=0;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) {
                s1+=(t[j+1]);
                pp.push_back(j);
            } else {
                s2+=(t[j+1]);
                cc.push_back(j);
            }
        }
        if (s1>s2) {
            int sc=cc.size(), sp=pp.size(), baj=0;
            for (int i=1; i<sc-1; i++) {
                if (2*cc[i]>cc[i+1]+cc[i-1]) {
                    baj=1;
                }
            }
            for (int i=1; i<sp-1; i++) {
                if (2*pp[i]<pp[i+1]+pp[i-1]) {
                    baj=1;
                }
            }
            if (!baj) {
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        sum=0, ans=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sum+=t[i];
        }
        kom[1]=t[1], kom[2]=t[2];
        skom[1]=t[1], skom[2]=t[1]+t[2];
        for (int i=3; i<=n; i++) {
            kom[i]=kom[i-2]+t[i];
            skom[i]=skom[i-1]+t[i];
        }
        // pp...ppcc...cc
        s2=0;
        for (int i=1; i<=n; i++) {
            s2+=t[i];
            if (2*s2>sum) {
                ans++;
            }
        }

        if (n==1) {
            cout << ans << "\n";
            continue;
        }
        if (n==2) {
            if (t[2]>t[1]) {
                ans++;
            }
            cout << ans << "\n";
            continue;
        }

        // cpcpcpcppppppp?
        if (n%2==0 && kom[n]>kom[n-1]) {
            ans++;
        }
        s2=0;
        for (int i=1; i<n-1; i+=2) {
            s2+=t[i];
            if (2*s2<sum) {
                ans++;
            }
            if (2*(s2+t[n])<sum) {
                ans++;
            }
        }
        // ?ccccccccpcpcp
        s2=0;
        for (int i=n; i>2; i-=2) {
            s2+=t[i];
            if (2*s2>sum) {
                ans++;
            }
            if (2*(s2+t[1])>sum) {
                ans++;
            }
        }
        //cout << "kezd " << ans << "\n";
        //cout << ans << "\n";

        // rossz, de igy jobban atlatom
        //solve(t[1]+t[n]);
        solve(t[1]+t[n]), solve(t[1]), solve(t[n]), solve(0);

        cout << ans%mod << "\n";
        //cout << trivi() << "\n";

    }
    return 0;
}
/*
1
4
1 1 1 10
*/
/*
ans%mod a vegen!!!!!
// nullazas!!
*/