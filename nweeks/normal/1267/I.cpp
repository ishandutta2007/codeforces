#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, pair<int, int>> dyn;

/*vector<int> p;
vector<vector<int>> better;*/

pair<int, int> lw(int i, int j) {
    if(dyn.count({i, j}))
        return dyn[{i, j}];

    cout << "? " << i + 1 << " " << j + 1 << "\n";
    cout << flush;
    char car;
    cin >> car;

    /*if(p[i] < p[j])
        car = '<';
    else
        car = '>';
    cout << car << endl;*/

    if(car == '<') {
        //better[j][i] = 1;
        dyn[{i, j}] = {i, j};
        dyn[{j, i}] = {i, j};
        return {i, j};
    }
    else{
        //better[i][j] = 1;
        dyn[{i, j}] = {j, i};
        dyn[{j, i}] = {j, i};
        return {j, i};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //srand(time(NULL));

    int nbTests;
    cin >> nbTests;

    for(int iTest = 0;iTest < nbTests;iTest++) {
        dyn.clear();
        
        int n;
        cin >> n;

        /*better = vector<vector<int>>(2 * n, vector<int>(2 * n, 0));

        for(int i = 0;i < 2 * n;i++) {
            p.push_back(i);
        }
        random_shuffle(p.begin(), p.end());

        for(int i = 0;i < 2 * n;i++) {
            cout << p[i] << " ";
        }
        cout << endl;*/

        vector<pair<int, int>> paires;
        for(int i = 0;i < n;i++) {
            paires.push_back(lw(i, i + n));
        }

        sort(paires.begin(), paires.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            if(a.first == b.first) return false;
            return lw(a.first, b.first).first == a.first;
        });

        vector<int> curs;
        for(int i = 0;i < n - 1;i++) {
            curs.push_back(paires[i].first);
            curs.push_back(paires[i].second);
        }

        sort(curs.begin(), curs.end(), [&](int a, int b) {
            if(a == b) return false;
            return lw(a, b).first == a;
        });

        lw(paires[n - 1].first, curs[(int)curs.size() - (n - 1)]);

        cout << "!\n";
        cout << flush;
    }

    /*for(int p = 0;p < 2 * n;p++) {
        for(int d = 0;d < 2 * n;d++) {
            for(int f = 0;f < 2 * n;f++) {
                if(d == f) continue;
                better[d][f] |= better[d][p] && better[p][f];
            }
        }
    }

    bool ok = false;
    for(int d = 0;d < 2 * n;d++) {
        for(int f = 0;f < 2 * n;f++) {
            if(f == d) continue;

            if(!better[d][f] && !better[f][d]
            && p[d] >= n && p[f] >= n) {
                ok = true;
            }

            if(p[d] == n - 1 && p[f] >= n && !better[f][d]) {
                cout << f + 1 << " " << d + 1 << endl;
                cout << "PROBLEME" << endl;
                return 0;
            }
        }
    }

    if(!ok) {
        cout << "PROBLEME" << endl;
    }*/
    return 0;
}