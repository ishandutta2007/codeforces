#include <bits/stdc++.h>

using namespace std;
const int c=16;
int n, n2;
long long sum, ert[c];
vector<pair<int, int> > dp[1<<c];
bool jo[1<<c];
map<long long, int> m;
set<long long> v, fr;
bool f(pair<int, int> a, pair<int, int> b) {
    return m[a.first]<m[b.first];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    n2=(1<<n);
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        for (int j=1; j<=x; j++) {
            int y;
            cin >> y;
            m[y]=i;
            sum+=y, ert[i]+=y;
        }
    }
    if (sum%n) {
        cout << "No\n";
        return 0;
    }
    sum/=n;
    for (auto x:m) {
        long long a=x.first;
        while (m.find(a)!=m.end() && v.find(a)==v.end() && fr.find(a)==fr.end()) {
            fr.insert(a);
            long long kov=a+sum-ert[m[a]];
            a=kov;
        }
        bool baj=0;
        if (fr.find(a)!=fr.end()) {
            vector<pair<int, int> > lep;
            int aa=a, mask=0;
            do {
                int kov=a+sum-ert[m[a]];
                lep.push_back({kov, m[a]});
                if (mask & (1<<(m[a]-1))) {
                    baj=1;
                }
                mask^=(1<<(m[a]-1));
                a=kov;

            } while (a!=aa);
            if (!baj && !jo[mask]) {
                dp[mask]=lep;
                jo[mask]=1;
            }
        }
        for (auto x:fr) {
            v.insert(x);
        }
        fr.clear();
    }
    for (int i=1; i<n2; i++) {
        if (!jo[i]) {
            for (int j=i; j>0; j=(j-1)&i) {
                if (jo[j] && jo[i-j]) {
                    jo[i]=1;
                    for (auto x:dp[j]) {
                        dp[i].push_back(x);
                    }
                    for (auto x:dp[i-j]) {
                        dp[i].push_back(x);
                    }
                    break;
                }
            }
        }
    }
    if (!jo[n2-1]) {
        cout << "No\n";
        cout << "\n";
    } else {
        cout << "Yes\n";
        vector<pair<int, int> > ans=dp[n2-1];
        sort(ans.begin(), ans.end(), f);
        for (auto x:ans) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}