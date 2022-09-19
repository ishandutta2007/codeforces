#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, xa[c], ya[c], xb[c], yb[c];
bool baj;
void solve(vector<int> &sz) {
    int si=sz.size();
    if (si==1) {
        return;
    }
    vector<pair<int, int> > p;
    for (auto x:sz) {
        p.push_back({xa[x], x});
    }
    sort(p.begin(), p.end());
    int maxi=0;
    for (int i=0; i<si; i++) {
        maxi=max(maxi, xb[p[i].second]);
        if (i<si-1 && xa[p[i+1].second]>=maxi) {
            vector<int> a, b;
            for (int j=0; j<=i; j++) {
                a.push_back(p[j].second);
            }
            for (int j=i+1; j<si; j++) {
                b.push_back(p[j].second);
            }
            solve(a), solve(b);
            return;
        }
    }


    p.clear();
    for (auto x:sz) {
        p.push_back({ya[x], x});
    }
    sort(p.begin(), p.end());
    maxi=0;
    for (int i=0; i<si; i++) {
        maxi=max(maxi, yb[p[i].second]);
        if (i<si-1 && ya[p[i+1].second]>=maxi) {
            vector<int> a, b;
            for (int j=0; j<=i; j++) {
                a.push_back(p[j].second);
            }
            for (int j=i+1; j<si; j++) {
                b.push_back(p[j].second);
            }
            solve(a), solve(b);
            return;
        }
    }
    baj=1;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> s;
    for (int i=1; i<=n; i++) {
        s.push_back(i);
        cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
    }
    solve(s);
    cout << (baj ? "NO" : "YES") << "\n";
    return 0;
}