#include <iostream>

using namespace std;

int n;
int k;
int t[200000];
int m[200000];
int p[200000];
int q;

int main() {
    cin >> n;
    k = n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        m[i] = 1;
        p[i] = i;
    }
    while (1) {
        int u = 0;
        int v = 0;
        /*cout << k << endl;
        for (int i = 0; i < n; i++) {
            cout << t[i] << " " << m[i] << " " << p[i] << endl;
        }*/
        for (int i = 0; i < k; i++) {
            int a = m[p[i]];
            while (p[i]+1<n && !m[p[i]+1]) {
                t[p[i]+1] = t[p[i]];
                m[p[i]] = 0;
                p[i]++;
            }
            m[p[i]] = a;
            if (p[i] == n-1 || t[p[i]] < t[p[i]+1]) {
                continue;
            }
            //cout << "poistuu " << t[p[i]+1] << endl;
            v++;
            m[p[i]+1] = 0;
            if (!a) continue;
            m[p[i]] = 1;
            p[u] = p[i];
            u++;
        }
        if (v > 0) q++;
        if (u == 0) break;
        k = u;
    }
    cout << q << endl;
}