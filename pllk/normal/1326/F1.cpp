#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
int w[20][20];

int t1[20];
int u1[1000][20];
int g1[1000];
void lol1(int c) {
    do {
        int b = 0;
        for (int i = 0; i+1 < c; i++) {
            b = 2*b+w[t1[i]][t1[i+1]];
        }
        u1[b][t1[c-1]]++;
        g1[b]++;
    } while (next_permutation(t1,t1+c));
}

int t2[20];
int u2[1000][20];
int g2[1000];
void lol2(int c) {
    do {
        int b = 0;
        for (int i = 0; i+1 < c; i++) {
            b = 2*b+w[t2[i]][t2[i+1]];
        }
        u2[b][t2[0]]++;
        g2[b]++;
    } while (next_permutation(t2,t2+c));
}

ll cc[1<<16];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            w[i][j] = s[j]-'0';
        }
    }
    int f = n <= 7 ? 1 : 7;
    for (int b = 0; b < (1<<n); b++) {
        int k = __builtin_popcount(b);
        if (k == f) {
            int c1 = 0;
            for (int i = 0; i < n; i++) {
                if (b&(1<<i)) t1[c1++] = i;
            }
            int c2 = 0;
            for (int i = 0; i < n; i++) {
                if (!(b&(1<<i))) t2[c2++] = i;
            }
            int k1 = 1<<c1;
            for (int i1 = 0; i1 < k1; i1++) {
                g1[i1] = 0;
                for (int h1 = 0; h1 < c1; h1++) {
                    u1[i1][t1[h1]] = 0;
                }
            }
            int k2 = 1<<c2;
            for (int i2 = 0; i2 < k2; i2++) {
                g2[i2] = 0;
                for (int h2 = 0; h2 < c2; h2++) {
                    u2[i2][t2[h2]] = 0;
                }
            }
            lol1(c1);
            lol2(c2);
            for (int i1 = 0; i1 < k1; i1++) {
                if (g1[i1] == 0) continue;
                for (int h1 = 0; h1 < c1; h1++) {
                    if (u1[i1][t1[h1]] == 0) continue;
                    for (int i2 = 0; i2 < k2; i2++) {
                        if (g2[i2] == 0) continue;
                        for (int h2 = 0; h2 < c2; h2++) {
                            //if (u2[i2][t2[h2]] == 0) continue;
                            int bb = i1*2+w[t1[h1]][t2[h2]];
                            bb *= (1<<(c2-1));
                            bb += i2;
                            cc[bb] += (ll)u1[i1][t1[h1]]*u2[i2][t2[h2]];
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < (1<<(n-1)); i++) {
        cout << cc[i] << " ";
    }
    cout << "\n";
}