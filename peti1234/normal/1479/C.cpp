#include <bits/stdc++.h>

using namespace std;
vector<pair<int, pair<int, int> > > sol;
void add(int a, int b, int c) {
    sol.push_back({a, {b, c}});
}
int l, r, n=22, k=21;
int main()
{
    cin >> l >> r;
    r++;
    for (int i=2; i<=k; i++) {
        add(i, n, 1);
        for (int j=i+1; j<=k; j++) {
            add(i, j, (1<<(k-j)));
        }
    }
    if (l==1) {
        add(1, n, 1);
        l++;
    }
    for (int i=2; i<=k; i++) {
        int ert=(1<<(k-i));
        if (r-l>=ert) {
            add(1, i, l-1);
            l+=ert;
        }
    }
    cout << "YES\n";
    cout << n << " " << sol.size() << "\n";
    for (int i=0; i<sol.size(); i++) {
        cout << sol[i].first << " " << sol[i].second.first << " " << sol[i].second.second << "\n";
    }
    return 0;
}