#include <bits/stdc++.h>

using namespace std;
const long long c=200002;
long long n, m, ki[c], tav[c];
vector<pair<pair<long long, long long>, long long> > el;
bool baj;
pair<long long, long long> holvan(long long a) {
    if (!ki[a]) {
        return {a, 0};
    }
    pair<long long, long long> p=holvan(ki[a]);
    p.second+=tav[a];
    ki[a]=p.first, tav[a]=p.second;
    return p;
}
bool unio(long long a, long long b, long long suly) {
    pair<long long, long long> aa=holvan(a), bb=holvan(b);
    long long afi=aa.first, ase=aa.second, bfi=bb.first, bse=bb.second;
    if (afi!=bfi) {
        ki[bfi]=afi;
        tav[bfi]=suly+ase-bse;
        return true;
    }
    return (suly+ase==bse);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (long long i=1; i<=m; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        el.push_back({{a, b}, c*d});
    }
    long long lo=0, hi=m+1, mid;
    while (hi-lo>1) {
        for (long long i=1; i<=n; i++) {
            ki[i]=0, tav[i]=0;
        }
        mid=(hi+lo)/2;
        baj=0;
        for (long long i=0; i<mid; i++) {
            if (!unio(el[i].first.first, el[i].first.second, el[i].second)) {
                baj=1;
            }
        }
        long long kie=holvan(1).first, kin=holvan(n).first;
        if (kie==kin && tav[1]>=tav[n]) {
            baj=1;
        }
        for (long long i=2; i<n; i++) {
            if (holvan(i).first==kie && tav[i]<=tav[1] || holvan(i).first==kin && tav[i]>=tav[n] || kie==kin && tav[i]>=tav[n]-tav[1]) {
                baj=1;
            }
        }
        if (baj) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    if (lo!=m) {
        cout << "BAD " << hi << "\n";
    } else if (holvan(1).first==holvan(n).first) {
        cout << tav[n]-tav[1] << "\n";
    } else {
        cout << "UNKNOWN\n";
    }
    return 0;
}