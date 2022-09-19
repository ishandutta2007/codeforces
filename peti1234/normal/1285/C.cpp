#include <bits/stdc++.h>

using namespace std;
long long x, xx, mini;
vector<long long> sz;
int main()
{
    cin >> x;
    xx=x, mini=x;
    for (long long i=2; i*i<=x; i++) {
        long long pr=1;
        while (x%i==0) {
            x/=i;
            pr*=i;
        }
        if (pr!=1) {
            sz.push_back(pr);
        }
    }
    if (x!=1) {
        sz.push_back(x);
    }
    int si=sz.size();
    for (int i=0; i<(1<<si); i++) {
        long long ert=1;
        for (int j=0; j<si; j++) {
            if (i & (1<<j)) {
                ert*=sz[j];
            }
        }
        mini=min(mini, max(ert, xx/ert));
    }
    cout << mini << " " << xx/mini << "\n";
    return 0;
}