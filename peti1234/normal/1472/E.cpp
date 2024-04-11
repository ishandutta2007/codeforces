#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, sol[c], pos, ert;
vector<pair<pair<int, int>, int> > mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, pos=0, ert=2e9;
        mini.clear();
        for (int i=1; i<=n; i++) {
            int a, b; cin >> a >> b;
            if (a<b) swap(a, b);
            mini.push_back({{a, -b}, i});
        }
        sort(mini.begin(), mini.end());
        for (int i=0; i<n; i++) {
            int s=-mini[i].first.second, id=mini[i].second;
            if (s>ert) {
                sol[id]=pos;
            } else {
                sol[id]=-1;
                pos=id, ert=s;
            }
        }
        for (int i=1; i<=n; i++) {
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}