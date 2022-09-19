#include <bits/stdc++.h>

using namespace std;
int x[3], y[3], a, b=1, c=2;
vector<pair<pair<int, int>, pair<int, int> > > ans;

int main()
{
    for (int i=0; i<3; i++) {
        cin >> x[i] >> y[i];
    }
    if (x[a]>x[b]) swap(a, b);
    if (x[a]>x[c]) swap(a, c);
    if (x[b]>x[c]) swap(b, c);
    if (x[a]!=x[b]) ans.push_back({{x[a], y[a]}, {x[b], y[a]}});
    if (x[b]!=x[c]) ans.push_back({{x[c], y[c]}, {x[b], y[c]}});
    int mini=min({y[0], y[1], y[2]}), maxi=max({y[0], y[1], y[2]});
    if (mini!=maxi) {
        ans.push_back({{x[b], mini}, {x[b], maxi}});
    }
    cout << ans.size() << "\n";
    for (auto p:ans) {
        cout << p.first.first << " " << p.first.second << " " << p.second.first << " " << p.second.second << "\n";
    }
    return 0;
}