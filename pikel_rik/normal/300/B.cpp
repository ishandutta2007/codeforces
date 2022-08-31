#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

vi group;
vvi comp;

void union_find(int a, int b) {
    int s1 = group[a];
    int s2 = group[b];

    if (s1 == s2)
        return;
    if (comp[s1].size() >= comp[s2].size()) {
        for (int i = 0; i < comp[s2].size(); i++) {
            comp[s1].push_back(comp[s2][i]);
            group[comp[s2][i]] = s1;
        }
        comp[s2].clear();
    }
    else {
        for (int i = 0; i < comp[s1].size(); i++) {
            comp[s2].push_back(comp[s1][i]);
            group[comp[s1][i]] = s2;
        }
        comp[s1].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    group.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        group[i] = i;
    }

    comp.resize(n + 1, vi(1));
    for (int i = 1; i <= n; i++) {
        comp[i] = {i};
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        union_find(a, b);
    }

    vector<bool> marked(n + 1);
    int flag = 0;

    vvi a1, a2, a3;

    for (int i = 1; i <= n; i++) {
        if (comp[i].size() > 3) {
            flag = 1;
            break;
        }
        if (comp[i].size() == 3)
            a3.push_back(comp[i]);
        else if (comp[i].size() == 2)
            a2.push_back(comp[i]);
        else if (comp[i].size() == 1)
            a1.push_back(comp[i]);
    }

    if (flag == 1 or a2.size() > a1.size() or (a1.size() - a2.size()) % 3 != 0) cout << "-1\n";
    else {
        int ptr1 = 0, ptr2 = 0;
        vvi ans;

        for (int i = 0; i < a3.size(); i++) {
            cout << a3[i][0] << " " << a3[i][1] << " " << a3[i][2] << "\n";
        }

        while (ptr1 < a1.size() and ptr2 < a2.size()) {
            cout << a1[ptr1][0] << " " << a2[ptr2][0] << " " << a2[ptr2][1] << "\n";
            ptr1 += 1;
            ptr2 += 1;
        }

        for (int i = ptr1; i < a1.size(); i+=3) {
            cout << a1[i][0] << " " << a1[i+1][0] << " " << a1[i+2][0] << "\n";
        }
    }
    return 0;
}