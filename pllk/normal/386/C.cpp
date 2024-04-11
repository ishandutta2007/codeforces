#include <iostream>

using namespace std;

#define ll long long

string s;
ll t;
int n;

int c[128];
int p[128];
int m;

int z[128];
int d;

ll laske(int k) {
    for (int i = 'a'; i <= 'z'; i++) c[i] = 0;
    m = 0;
    int i = -1, j = -1;
    ll q = 0;
    while (true) {
        while (m < k && j < n-1) {
            j++;
            if (c[s[j]] == 0) m++;
            c[s[j]] = 1;
            p[s[j]] = j;
        }
        if (m < k) break;
        int up = n+1;
        for (int h = 'a'; h <= 'z'; h++) {
            if (c[h]) up = min(up, p[h]);
        }
        q += up-i;
        while (j < n-1 && c[s[j+1]]) {
            j++;
            p[s[j]] = j;
            up = n+1;
            for (int h = 'a'; h <= 'z'; h++) {
                if (c[h]) up = min(up, p[h]);
            }
            q += up-i;
        }
        i = up;
        c[s[up]] = 0;
        m--;
    }
    return q;
}

int main() {
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (z[s[i]] == 0) {
            z[s[i]] = 1;
            d++;
        }
    }
    cout << d << endl;
    for (int i = 1; i <= d; i++) {
        cout << laske(i) << endl;
    }
}