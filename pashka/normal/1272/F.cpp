#include <bits/stdc++.h>
#include <cassert>
#define long long long int
using namespace std;

// @author: pashka

int d[222][222][444];
char c[222][222][444];
int pi[222][222][444];
int pj[222][222][444];
int pk[222][222][444];

int main() {
    ios::sync_with_stdio(false);

    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size();
    int n2 = s2.size();

    memset(d, 0x7f, sizeof(d));

    d[0][0][0] = 0;
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            for (int k = 0; k <= n1 + n2; k++) {
                // '('
                int ii = i < n1 && s1[i] == '(' ? i + 1 : i;
                int jj = j < n2 && s2[j] == '(' ? j + 1 : j;
                int kk = k + 1;
                if (d[ii][jj][kk] > d[i][j][k] + 1) {
                    d[ii][jj][kk] = d[i][j][k] + 1;
                    pi[ii][jj][kk] = i;
                    pj[ii][jj][kk] = j;
                    pk[ii][jj][kk] = k;
                    c[ii][jj][kk] = '(';
                }
                // ')'
                if (k > 0) {
                    ii = i < n1 && s1[i] == ')' ? i + 1 : i;
                    jj = j < n2 && s2[j] == ')' ? j + 1 : j;
                    kk = k - 1;
                    if (d[ii][jj][kk] > d[i][j][k] + 1) {
                        d[ii][jj][kk] = d[i][j][k] + 1;
                        pi[ii][jj][kk] = i;
                        pj[ii][jj][kk] = j;
                        pk[ii][jj][kk] = k;
                        c[ii][jj][kk] = ')';
                    }
                }
            }
        }
    }
    int res = INT_MAX;
    int bestk = -1;
    for (int k = 0; k <= n1 + n2; k++) {
        int s = d[n1][n2][k] + k;
        if (s < res) {
            res = s;
            bestk = k;
        }
    }
//    cout << res << " " << bestk << "\n";
    string s;
    for (int i = 0; i < bestk; i++) {
        s += ')';
    }
    int i = n1;
    int j = n2;
    int k = bestk;

    while(i > 0 || j > 0 || k > 0) {
        char cc = c[i][j][k];
//        cout << i << " " << j << " " << k << " " << cc << "\n";
        int ii = pi[i][j][k];
        int jj = pj[i][j][k];
        int kk = pk[i][j][k];
        i = ii;
        j = jj;
        k = kk;
        s += cc;
//        if (s.size() == 20) break;
    }
    reverse(s.begin(), s.end());
    cout << s;

    assert(s.size() == res);

    i = 0; j = 0; k = 0;
    for (char c : s) {
        if (i < n1 && s1[i] == c) i++;
        if (j < n2 && s2[j] == c) j++;
        if (c == '(') k++; else k--;
        assert(k >= 0);
    }
    assert(i == n1 && j == n2);

    return 0;
}