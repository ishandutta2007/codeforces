#include <iostream>

using namespace std;

#define N (1<<17)

int p[2*N][26];
int u[2*N];

void alas(int k, int a, int b) {
    if (u[k] == -1) return;
    for (int i = 0; i < 26; i++) {
        if (i == u[k]) p[k][i] = b-a+1;
        else p[k][i] = 0;
    }
    if (2*k < 2*N) u[2*k] = u[k];
    if (2*k+1 < 2*N) u[2*k+1] = u[k];
    u[k] = -1;
}

void muuta(int k, int a, int b, int c, int d, int m) {
    alas(k, a, b);
    if (a == c && b == d) {
        u[k] = m;
        for (int i = 0; i < 26; i++) {
            if (i == m) p[k][i] = b-a+1;
            else p[k][i] = 0;
        }
        return;
    }
    if (d < a || c > b) return;
    int w = (b-a+1)/2;
    muuta(2*k, a, a+w-1, c, min(d,a+w-1), m);
    muuta(2*k+1, a+w, b, max(c,a+w), d, m);
    for (int i = 0; i < 26; i++) {
        p[k][i] = p[2*k][i]+p[2*k+1][i];
    }
}

int tt;
void laske(int k, int a, int b, int c, int d, int m) {
    alas(k, a, b);
    if (a == c && b == d) {
        tt += p[k][m];
        return;
    }
    if (d < a || c > b) return;
    int w = (b-a+1)/2;
    laske(2*k, a, a+w-1, c, min(d,a+w-1), m);
    laske(2*k+1, a+w, b, max(c,a+w), d, m);
}

int n, q;
string s;

void tulos() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            tt = 0;
            laske(1, 0, N-1, i, i, j);
            if (tt) {
                cout << (char)(j+'a');
                break;
            }
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 2*N; i++) u[i] = -1;
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < n; i++) {
        muuta(1, 0, N-1, i, i, s[i]-'a');
    }
    for (int h = 0; h < q; h++) {
        int i, j, k;
        cin >> i >> j >> k;
        i--; j--;
        int c[26];
        for (int z = 0; z < 26; z++) {
            tt = 0;
            laske(1, 0, N-1, i, j, z);
            c[z] = tt;
        }
        if (k == 1) {
            int a = i;
            for (int z = 0; z < 26; z++) {
                if (c[z] == 0) continue;
                muuta(1, 0, N-1, a, a+c[z]-1, z);
                a += c[z];
            }
        } else {
            int a = i;
            for (int z = 25; z >= 0; z--) {
                if (c[z] == 0) continue;
                muuta(1, 0, N-1, a, a+c[z]-1, z);
                a += c[z];
            }
        }
    }
    tulos();
}