#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int n, bal=1, jobb=1, baj;
long double l[c], r[c], h[c], mini=1e18;
vector<pair<long double, pair<int, int> > > sz;
bool cmp(int a, int b) {
    return (h[a]>h[b] || (h[a]==h[b] && l[a]<l[b]));
}
void ch(long double ert) {
    long double kis=l[bal]+h[bal]*ert, nagy=r[jobb]+h[jobb]*ert;
    mini=min(mini, nagy-kis);
}
void add(long double a, int b, int c) {
    sz.push_back({a, {b, c}});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> l[i] >> r[i] >> h[i];
        if (cmp(i, bal)) {
            bal=i;
        }
        if (cmp(jobb, i)) {
            jobb=i;
        }
    }
    ch(-1e7);
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (h[i]!=h[j]) {
                int a=i, b=j;
                if (!cmp(a, b)) {
                    swap(a, b);
                }
                long double mp1=(l[b]-r[a])/(h[a]-h[b]), mp2=(r[b]-l[a])/(h[a]-h[b]);
                add(mp1, c, c);
                add(mp2, a, b);
            }
        }
    }
    sort(sz.begin(), sz.end());
    for (auto i:sz) {
        long double ert=i.first;
        int fi=i.second.first, se=i.second.second;
        if (fi==c) {
            if (!baj) {
                ch(ert);
            }
            baj++;
        } else {
            baj--;
            if (bal==fi) {
                bal=se;
            }
            if (jobb==se) {
                jobb=fi;
            }
            if (!baj) {
                ch(ert);
            }
        }
    }
    cout.precision(15);
    cout << mini << "\n";
    return 0;
}