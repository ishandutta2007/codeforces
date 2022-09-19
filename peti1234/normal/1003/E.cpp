#include <bits/stdc++.h>

using namespace std;
int n, d, k, ert;
vector<pair<int, int> > ans;
void add(int a, int b) {
    ans.push_back({a, b});
}
void dfs(int a, int deg, int szint) {
    //cout << "dfs " << a << " " << deg << " " << szint << "\n";
    while (szint>0 && deg>0 && ert<n) {
        add(a, ++ert);
        deg--;
        dfs(ert, k-1, szint-1);
    }
}
void ns() {
    cout << "NO\n";
    exit(0);
}
int main()
{
    cin >> n >> d >> k;
    if (n==1) {
        ns();
    }
    if (k==1) {
        if (n>2 || d>1) ns();
        else {
            cout << "YES\n";
            cout << 1 << " " << 2 << "\n";
        }
        return 0;
    }
    ert=d+1;
    for (int i=1; i<=d; i++) {
        add(i, i+1);
        int k1=(d+2)/2, k2=(d+3)/2;
        dfs(i, k-2, d/2-min(abs(i-k1), abs(i-k2)));
    }
    if (ert!=n) {
        ns();
    } else {
        cout << "YES\n";
        for (auto x:ans) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}