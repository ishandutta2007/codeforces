#include <bits/stdc++.h>

using namespace std;
const long long c=1002, gy=4e3, h=1e18;
long long n, k, t[c], prh[c], cnt;
bool v[c];
vector<pair<long long, long long> > pr;
vector<long long> alap;
map<long long, long long> m;
long long calc(long long x) {
    long long gyok=sqrt(x);
    if (gyok*gyok==x) {
        x=gyok;
    }
    long long kgyok=cbrt(x);
    if (kgyok*kgyok*kgyok==x) {
        x=kgyok;
    }
    for (long long i=2; i<=gy; i++) {
        if (x%i==0) {
            while (x%i==0) {
                x/=i;
            }
            if (x==1) {
                return i;
            }
            return 0;
        }
    }
    return x;
}
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        long long x=m[t[i]];
        if (x) {
            if (!v[x]) {
                v[x]=1;
                alap.push_back(prh[x]);
                pr.push_back({prh[x], t[x]});
                v[i]=1;
                pr.push_back({prh[x], t[i]});
            }
            continue;
        }
        prh[i]=calc(t[i]);
        if (prh[i]) {
            long long x=prh[i], ert=x;
            while (h/x>=ert) {
                ert*=x;
                m[ert]=i;
            }
        }
    }
    cnt=pr.size();
    if (k>=cnt) {
        for (int i=1; i<=n; i++) {
            if (!v[i] && cnt<k) {
                long long x=t[i];
                for (long long oszt:alap) {
                    while (x%oszt==0) {
                        x/=oszt;
                    }
                }
                if (x==1) {
                    v[i]=1;
                    cnt++;
                }
            }
        }
        if (cnt<k) {
            cout << 0 << "\n";
        } else {
            for (int i=1; i<=n; i++) {
                if (v[i]) {
                    cout << t[i] << " ";
                }
            }
            cout << "\n";
        }
    } else {
        if (k%2==0) {
            for (int i=0; i<k; i++) {
                cout << pr[i].second << " ";
            }
            cout << "\n";
            return 0;
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                long long x=t[i];
                int si=0;
                set<long long> s;
                for (long long oszt: alap) {
                    if (x%oszt==0) {
                        s.insert(oszt);
                        si++;
                    }
                    while (x%oszt==0) {
                        x/=oszt;
                    }
                }
                if (x==1 && 2*si<k) {
                    cout << t[i] << " ";
                    k--;
                    for (auto id:pr) {
                        long long fi=id.first, se=id.second;
                        if (s.find(fi)!=s.end()) {
                            cout << se << " ";
                            k--;
                        }
                    }
                    for (auto id:pr) {
                        long long fi=id.first ,se=id.second;
                        if (k && s.find(fi)==s.end()) {
                            cout << se << " ";
                            k--;
                        }

                    }
                    cout << "\n";
                    return 0;
                }
            }
        }
        cout << "0\n";
    }
    return 0;
}