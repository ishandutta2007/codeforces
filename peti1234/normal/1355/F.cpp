#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll c=5002, sok=1e18;
bool pr[c];
ll w, mo, cnt, szam, lno;
vector<pair<ll, ll> > kerd;
vector<pair<ll, ll> > volt;
int main()
{
    for (int i=2; i<c; i++) if (!pr[i]) for (int j=2*i; j<c; j+=i) pr[j]=1;
    cin >> w;
    while(w--) {
        mo=1, kerd.clear(), cnt=2, szam=1;
        for (int i=1; i<=22; i++) {
            while(sok/szam>cnt) {
                if (!pr[cnt]) kerd.push_back({cnt, cnt}), szam*=cnt;
                cnt++;
            }
            cout.flush() << "? " << szam << "\n";
            cin >> lno;
            for (int i=0; i<kerd.size(); i++) {
                ll fi=kerd[i].first, se=kerd[i].second;
                if (lno%se==0) volt.push_back({fi, se*fi});
                else {
                    szam/=se;
                    ll db=0, p=1;
                    while(p<se) p*=fi, db++;
                    mo*=db;
                }
            }
            szam=1, kerd.clear();
            for (int i=0; i<volt.size(); i++) kerd.push_back({volt[i].first, volt[i].second}), szam*=volt[i].second;
            if (i==22) {
                for (int i=0; i<volt.size(); i++) {
                    ll fi=volt[i].first, se=volt[i].second;
                    if (lno%se==0) volt.push_back({fi, se*fi});
                    else {
                        szam/=se;
                        ll db=0, p=1;
                        while(p<se) p*=fi, db++;
                        mo*=db;
                    }
                }
            }
            volt.clear();
        }
        cout.flush() << "! " << max(2*mo, mo+7) << "\n";
    }
    return 0;
}