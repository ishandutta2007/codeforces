#include <bits/stdc++.h>

using namespace std;
int w, n, x;
vector<pair<int, int> > regi, uj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        regi.push_back({0, 0});
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            for (auto s:regi) {
                int a=s.first, b=s.second;
                uj.push_back({a+x, max(0, b-x)});
                uj.push_back({max(0, a-x), b+x});
            }
            sort(uj.begin(), uj.end()), regi.clear();
            int mini=1e9;
            for (auto x:uj) {
                if (x.second<mini) {
                    mini=x.second;
                    regi.push_back(x);
                }
            }
            uj.clear();
        }

        int mini=1e9;
        for (auto x:regi) {
            mini=min(mini, x.first+x.second);
        }
        cout << mini << "\n";
        regi.clear(), uj.clear();
    }
    return 0;
}