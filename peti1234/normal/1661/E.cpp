#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int q, n, ert[c], db[c], pref[c], spec[c], ut, kesz;
vector<pair<int, int> > sz;
int f(int a) {
    return (a==0 ? 0 : a==5 ? 2 : 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int j=0; j<3; j++) {
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            /*if (49<=i && i<=62) {
                cout << c;
            }*/
            if (c=='1') ert[i]+=(1<<j);
        }
        //cout << "\n";
    }
    for (int i=1; i<=n; i++) {
        db[i]=max(0, f(ert[i])-f(ert[i] & ert[i-1]));
        pref[i]=pref[i-1]+db[i];
    }
    for (int i=n; i>=1; i--) {
        if (ert[i]==5 && ert[i+1]==7) spec[i]=i+1;
        else if (0<ert[i] && ert[i]<7 && (ert[i] & ert[i+1]) && (spec[i+1] || ert[i]==5 && ert[i+1]==7)) spec[i]=spec[i+1];
    }
    sz.push_back({0, 0});
    for (int i=1; i<=n; i++) {
        if (db[i]) {
            ut=i, kesz=0;
        }
        if (!kesz && ert[i]==7 && ert[i-1]==5) {
            sz.push_back({ut, i});
            //cout << "par " << ut << " " << i << "\n";
            kesz=1;
        }
        if (ert[i]==7) {
            kesz=1;
        }
    }
    sz.push_back({n+1, n+1});
    cin >> q;
    while (q--) {
        int l, l2, r;
        cin >> l >> r;
        int ans=pref[r]-pref[l]+f(ert[l]), valt=0;
        if (spec[l] && spec[l]<=r) {
            ans--;
        }
        l2=(spec[l] ? spec[l] : l);
        int si=sz.size(), lo=-1, hi=si, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (sz[mid].second>r) {
                hi=mid;
            } else {
                lo=mid;
            }
        }
        valt=hi-1;
        lo=-1, hi=si;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (sz[mid].first<=l2) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        valt-=lo;
        valt=max(0, valt);
        //cout << "alap " << ans << " " << valt << "\n";
        //cout << "valasz.............. ";
        cout << ans-valt << "\n";

    }
    return 0;
}
/*
100
0111001011010100011001000101110011010000001000010111011111100110000010101010111001110011001100111000
0000001100011010111110111101010011001100100100100011011001111100100111101001101100100001011100000111
1001010011100000000000011111000001110110110001101110110110000100010011111000011110001000110000111000
1
49 62
*/