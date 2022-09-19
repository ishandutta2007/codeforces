#include <bits/stdc++.h>

using namespace std;
int w, jo, n;
vector<pair<int, int> > p;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, jo=0, p.clear();
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            p.push_back({x, i});
        }
        sort(p.begin(), p.end());
        for (int i=0; i<n; i++) if (p[i].first%p[0].first && p[i].second!=i) jo=1;
        if (!jo) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}