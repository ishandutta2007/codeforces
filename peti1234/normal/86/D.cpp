#include <bits/stdc++.h>

using namespace std;
const int c=1000002;
long long n, q, t[c], db[c], sol[c], ans, l=1, r=0;
vector<pair<pair<long long, int>, pair<int, int> > > sz;
void add(int a, int b) {
    long long s=t[a];
    if (b==1) {
        ans+=(2*db[s]+1)*s;
    } else {
        ans-=(2*db[s]-1)*s;
    }
    db[s]+=b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=q; i++) {
        long long a, b, ert; cin >> a >> b, ert=(a/400)*c+b;
        sz.push_back({{ert, i}, {a, b}});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<q; i++) {
        int ki=sz[i].first.second, a=sz[i].second.first, b=sz[i].second.second;
        while (r<b) {
            r++;
            add(r, 1);
        }
        while (l>a) {
            l--;
            add(l, 1);
        }
        while (r>b) {
            add(r, -1);
            r--;
        }
        while (l<a) {
            add(l, -1);
            l++;
        }
        sol[ki]=ans;
    }
    for (int i=1; i<=q; i++) {
        cout << sol[i] << "\n";
    }
    return 0;
}