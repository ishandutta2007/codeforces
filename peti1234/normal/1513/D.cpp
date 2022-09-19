#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, ki[c];
long long p, sum, t[c], db;
vector<pair<long long, int> > ert;
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    return ki[a]=holvan(ki[a]);
}
bool unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[a]=b;
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> p;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            ert.push_back({t[i], i});
        }
        sort(ert.begin(), ert.end());
        for (auto i:ert) {
            long long val=i.first;
            int pos=i.second;

            if (val<p) {
                for (int i=pos-1; i>=1; i--) {
                    if (__gcd(t[i], t[pos])!=val) {
                        break;
                    }
                    if (!unio(i, pos)) {
                        break;
                    } else {
                        sum+=val;
                        db++;
                    }
                }
                for (int i=pos+1; i<=n; i++) {
                    if (__gcd(t[i], t[pos])!=val) {
                        break;
                    }
                    if (!unio(i, pos)) {
                        break;
                    } else {
                        sum+=val;
                        db++;
                    }
                }
            }
        }
        cout << sum+(n-1-db)*p << "\n";
        ert.clear();
        sum=0, db=0;
        for (int i=1; i<=n; i++) {
            t[i]=0;
            ki[i]=0;
        }
    }
    return 0;
}
/*
1
2 5
3 3
*/