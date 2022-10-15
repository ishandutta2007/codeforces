#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define N (1<<18)

int p[2][2*N][2];

void alas(int q, int k) {
    int v = p[q][k][1];
    p[q][k][0] = max(p[q][k][0], p[q][k][1]);
    p[q][k][1] = 0;
    if (2*k < 2*N) {
        p[q][2*k][1] = max(p[q][2*k][1],v);
    }
    if (2*k+1 < 2*N) {
        p[q][2*k+1][1] = max(p[q][2*k+1][1],v);
    }
}

void muuta(int q, int a, int b, int k, int c, int d, int x) {
    alas(q, k);
    if (b < c || a > d) return;
    if (a == c && b == d) {
        p[q][k][1] = max(p[q][k][1],x);
        return;
    }
    p[q][k][0] = max(p[q][k][0],x);
    int w = d-c+1;
    muuta(q, a, min(b,c+w/2-1), 2*k, c, c+w/2-1, x);
    muuta(q, max(a,c+w/2), b, 2*k+1, c+w/2, d, x);
}

int suurin(int q, int a, int b, int k, int c, int d) {
    alas(q, k);
    if (b < c || a > d) return 0;
    if (a == c && b == d) {
        return p[q][k][0];
    }
    int w = d-c+1;
    return max(suurin(q, a, min(b,c+w/2-1), 2*k, c, c+w/2-1),
               suurin(q, max(a,c+w/2), b, 2*k+1, c+w/2, d));
}

int n, qq;
int a[202020][3];
vector<int> xv, yv;
unordered_map<int,int> xu, yu;
int xr[202020], yr[202020];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> qq;
    for (int i = 0; i < qq; i++) {
        int x, y;
        char s;
        cin >> x >> y >> s;
        a[i][0] = x;
        a[i][1] = y;
        a[i][2] = (s == 'U');
        xv.push_back(x);
        yv.push_back(y);
    }
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());
    int xc = 0;
    for (int i = 0; i < xv.size(); i++) {
        if (i > 0 && xv[i-1] == xv[i]) continue;
        xc++;
        xu[xv[i]] = xc;
        xr[xc] = xv[i];
    }
    int yc = 0;
    for (int i = 0; i < yv.size(); i++) {
        if (i > 0 && yv[i-1] == yv[i]) continue;
        yc++;
        yu[yv[i]] = yc;
        yr[yc] = yv[i];
    }
    unordered_map<int,unordered_map<int,int>> mm;
    for (int i = 0; i < qq; i++) {
        if (mm[a[i][0]][a[i][1]]) {
            cout << "0\n";
            continue;
        }
        mm[a[i][0]][a[i][1]] = 1;
        if (a[i][2] == 0) {
            int k = suurin(0, yu[a[i][1]], yu[a[i][1]], 1, 0, N-1);
            cout << a[i][0]-xr[k] << "\n";
            muuta(1, k+1, xu[a[i][0]], 1, 0, N-1, yu[a[i][1]]);
        } else {
            int k = suurin(1, xu[a[i][0]], xu[a[i][0]], 1, 0, N-1);
            cout << a[i][1]-yr[k] << "\n";
            muuta(0, k+1, yu[a[i][1]], 1, 0, N-1, xu[a[i][0]]);
        }
    }
}