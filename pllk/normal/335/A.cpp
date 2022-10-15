#include <iostream>

using namespace std;

string s;
int n, m;
int t[256];
char v[2000];

bool kelpaa(int k) {
    int p = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (t[i] == 0) continue;
        int q;
        if (t[i]%k == 0) q = t[i]/k;
        else q = t[i]/k+1;
        for (int j = 0; j < q; j++) {
            if (p == n) return 0;
            v[p] = i;
            p++;
        }
    }
    while (p < n) {
        v[p] = 'a';
        p++;
    }
    v[p] = 0;
    return 1;
}

int main() {
    cin >> s >> n;
    m = s.length();
    for (int i = 0; i < m; i++) t[s[i]]++;
    for (int i = 1; i <= m; i++) {
        if (kelpaa(i)) {
            cout << i << endl;
            cout << v << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}