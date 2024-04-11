#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 4e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int nbMaitres;
    cin >> nbMaitres;

    vector<int> deb(nbMaitres), fin(nbMaitres), temps(nbMaitres);
    for (int i = 0; i < nbMaitres; ++i)
        cin >> deb[i] >> fin[i]>> temps[i];

    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>>
                    pqAvant, pqActuel;
    int curT = 0;
    int sol = 0;
    for (int i = 0; i < nbMaitres; ++i) {
        pqAvant.emplace(deb[i] + temps[i], i);
    }

    while (!pqAvant.empty() or !pqActuel.empty()) {
        while (!pqAvant.empty()
            and deb[pqAvant.top().second] <= curT) {
                auto [x, i] = pqAvant.top();
                pqAvant.pop();
                pqActuel.emplace(temps[i], i);
            }
        if (pqActuel.empty() and pqAvant.empty())
            break;
        int bestAvant = INF;
        int bestActuel = INF;
        if (pqAvant.empty() == false)
            bestAvant = pqAvant.top().first;
        if (!pqActuel.empty())
            bestActuel = curT + pqActuel.top().first;

        if (bestAvant < bestActuel) {
            auto [x, i] = pqAvant.top();
            sol++;
            curT = x;
        } else {
            auto [t, i] = pqActuel.top();
            // curT + k * t <= min(bestAvant, b[i])
            int k = (min(fin[i], bestAvant) - curT) / t;
            if (k <= 0) {
                pqActuel.pop();
                continue;
            }
            sol += k;
            curT += k * t;
            
        }
    }
    cout << sol << endl;
}