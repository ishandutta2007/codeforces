#include <bits/stdc++.h>

using namespace std;
int n, dbu=1, dbt;
vector<int> u, sz, ans;
string s;
bool baj;
void tolt(int a, int b) {
    if (a<1 || a==2 || (a%2==0 && b<2) || (a>1 && b==0)) {
        baj=1;
    }
    if (a%2==0) {
        ans.push_back(2);
        a-=3;
    }
    for (int i=1; 2*i<=a; i++) {
        ans.push_back(1);
    }
    return;
}
void solve(int a) {
    if (ans.size()) {
        return;
    }
    baj=0;
    for (int i=0; i<n; i++) {
        tolt(u[i]-a, a);
        ans.push_back(sz[i]+a);
    }
    tolt(u[n]-a, a);
    if (baj) {
        ans.clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    n=s.size();
    for (int i=0; i<n; i++) {
        if (s[i]=='#') {
            if (dbu) {
                u.push_back(dbu);
            }
            dbu=0;
            dbt++;
        }
        if (s[i]=='_') {
            if (dbt) {
                sz.push_back(dbt);
            }
            dbt=0;
            dbu++;
        }
    }
    if (dbt) {
        sz.push_back(dbt);
    }
    dbu++;
    u.push_back(dbu);
    n=sz.size();
    if (!n) {
        cout << "0\n\n";
    } else {
        solve(0), solve(1), solve(2), solve(3);
        if (ans.size()) {
            cout << ans.size() << "\n";
            for (int i:ans) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}