#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define A 999999999

int n;

int q[128];
int v[111];
int a[111];

int x[10];
int y[10];

bool ok() {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (v[i] == v[j] && a[i] != a[j] && !y[a[i]] && !y[a[j]]) return false;
            if (!x[v[i]] && !x[v[j]] && a[i] != a[j] && !y[a[i]] && !y[a[j]]) return false;
            if (a[i] == a[j] && v[i] != v[j] && !x[v[i]] && !x[v[j]]) return false;
            if (!y[a[i]] && !y[a[j]] && v[i] != v[j] && !x[v[i]] && !x[v[j]]) return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    q['R'] = 0;
    q['G'] = 1;
    q['B'] = 2;
    q['Y'] = 3;
    q['W'] = 4;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v[i] = q[s[0]];
        a[i] = s[1]-'0'-1;
    }
    int t = A;
    for (int i = 0; i < (1<<5); i++) {
        for (int j = 0; j < (1<<5); j++) {
            int c = 0;
            for (int k = 0; k < 5; k++) {
                if (i&(1<<k)) {x[k] = 1; c++;}
                else x[k] = 0;
            }
            for (int k = 0; k < 5; k++) {
                if (j&(1<<k)) {y[k] = 1; c++;}
                else y[k] = 0;
            }
            if (!ok()) continue;
            t = min(t, c);
        }
    }
    cout << t << "\n";
}