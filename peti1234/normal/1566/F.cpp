#include <bits/stdc++.h>

using namespace std;
long long w, n, m;
long long dp[200005], sok=1e16;
set<long long> p;
vector<pair<long long, long long> > s1, s2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m;
        for (long long i=1; i<=n; i++) {
            long long x;
            cin >> x;
            p.insert(x);
        }
        for (long long i=1; i<=m; i++) {
            long long l, r;
            cin >> l >> r;
            auto s=p.lower_bound(l);
            if (s==p.end() || (*s)>r) {
                //cout << "kezd " << l << " " << r << " " << *s << "\n";
                s1.push_back({l, r});
            }
        }
        sort(s1.rbegin(), s1.rend());
        long long minert=2e9, si=s1.size();
        for (long long i=0; i<si; i++) {
            long long ert=s1[i].second;
            if (ert<minert && (i==0 || s1[i].second!=s1[i-1].second)) {
                s2.push_back(s1[i]);
            }
            minert=min(minert, ert);
        }

        sort(s2.begin(), s2.end());

        /*cout << "vonalak\n";
        for (auto x:s2) {
            cout << x.first << " " << x.second << "\n";
        }*/
        si=s2.size();
        for (long long i=1; i<=si; i++) {
            dp[i]=sok;
        }
        long long pos=0;
        for (auto x:p) {
            //cout << "pont " << x << "\n";
            long long spec=sok, spec2=sok;
            while (pos<si && x>s2[pos].second) {
                long long ert=s2[pos].second;
                spec=min(spec, dp[pos]+x-ert);
                spec2=min(spec2, dp[pos]+2*(x-ert));
                pos++;
            }

            dp[pos]=min(dp[pos], spec2);
            //cout << "pos " << pos << " " << dp[pos] << "\n";
            auto it=p.find(x);
            it++;
            long long kov=(it==p.end() ? sok : *it);
            for (long long i=pos; i<si; i++) {
                if (s2[i].first>kov) {
                    break;
                }
                //dp[i+1]=dp[pos]+s2[i].first-x;
                dp[i+1]=min(dp[pos]+s2[i].first-x, spec+2*(s2[i].first-x));
            }
            dp[pos]=min(dp[pos], spec);
        }

        //cout << "valasz: ";
        cout << dp[si] << "\n";

        for (long long i=0; i<=si; i++) {
            dp[i]=0;
        }
        p.clear();
        s1.clear(), s2.clear();
    }
    return 0;
}
/*
1
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19
*/