#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, lenG, lenD;
    cin >> n >> m >> lenG >> lenD;
    vector<int> prufG(lenG), prufD(lenD);
    for (int &x : prufG) {
        cin >> x;
        --x;
    }
    for (int &x : prufD) {
        cin >> x;
        --x;
    }
    reverse(prufG.begin(), prufG.end());
    reverse(prufD.begin(), prufD.end());

    if (lenG >= m or lenD >= n) {
        cout << "No\n";
        return 0;
    }

    vector<int> occs(n + m+1);
    vector<pair<int, int>> sol;

    priority_queue<int,
                 vector<int>,
                  greater<int>> feuilles;
    for (int x : prufG)
        occs[x]++;
    for (int x : prufD)
        occs[x]++;
    for (int i = 0; i < n+m; ++i)
        if (!occs[i])
            feuilles.push(i);
    vector<int> aPlacerG, aPlacerD;
    while (!prufG.empty() or !prufD.empty()) {
        assert(!feuilles.empty());
        int f = feuilles.top();
        feuilles.pop();
        if (f < n) {
            if (prufD.empty())
                aPlacerG.push_back(f);
            else {
                int g = prufD.back();
                prufD.pop_back();
                sol.emplace_back(f, g);
                occs[g]--;
                if (!occs[g])
                    feuilles.push(g);
            }
        } else {
            if (prufG.empty())
                aPlacerD.push_back(f);
            else {
                int g = prufG.back();
                prufG.pop_back();
                sol.emplace_back(g, f);
                occs[g]--;
                if (!occs[g])
                    feuilles.push(g);
            }
        }
    }
    assert(feuilles.size() >= 2);
    while (!feuilles.empty()) {
        int x = feuilles.top();
        feuilles.pop();
        if (x < n)
            aPlacerG.push_back(x);
        else
            aPlacerD.push_back(x);
    }
    assert(!aPlacerG.empty() and !aPlacerD.empty());
    for (int x : aPlacerG)
        sol.emplace_back(x, aPlacerD[0]);
    for (int i = 1; i < (int)aPlacerD.size(); ++i)
        sol.emplace_back(aPlacerG[0], aPlacerD[i]);
    cout << "Yes\n";
    for (auto [u, v] : sol) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
}