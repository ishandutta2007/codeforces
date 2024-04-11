#include <iostream>
#include <vector>
#include <algorithm>

#define K 3005

using namespace std;

int n;

int a[K][K];
int b[K][K];
int c1[K][K];
int c2[K][K];
int d1[K][K];
int d2[K][K];
int e[K][K];
int s[K][K];

bool v;

void tutki(int y, int x) {
    vector<pair<int, int> > q;
    while (y < K && x < K) {
        if (a[y][x]) {
            q.push_back(make_pair(y, x));
        }
        if (b[y][x]) {
            for (int i = 0; i < q.size(); i++) {
                int vy = q[i].first;
                int vx = q[i].second;
                if (!e[vy][x] || !e[y][vx]) continue;
                int p = s[y][x];
                if (vy > 0) p -= s[vy-1][x];
                if (vx > 0) p -= s[y][vx-1];
                if (vy > 0 && vx > 0) p += s[vy-1][vx-1];
                if (p < (y-vy+1)*(x-vx+1)) continue;
                if (c1[vy][x] == -1 || c1[vy][x] > vx) continue;
                if (c2[y][x] == -1 || c2[y][x] > vx) continue;
                if (d1[y][vx] == -1 || d1[y][vx] > vy) continue;
                if (d2[y][x] == -1 || d2[y][x] > vy) continue;
                vector<int> z;
                for (int i = vy; i <= y; i++) {
                    for (int j = vx; j <= x; j++) {
                        if (a[i][j]) z.push_back(a[i][j]);
                    }
                }
                cout << "YES " << z.size() << endl;
                for (int i = 0; i < z.size(); i++) {
                    cout << z[i] << " ";
                }
                cout << endl;
                v = true;
                return;
            }
        }
        y++; x++;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2-x1 == y2-y1) {
            cout << "YES 1" << endl;
            cout << (i+1) << endl;
            return 0;
        }
        a[y1][x1] = i+1;
        b[y2-1][x2-1] = i+1;
        e[y1][x1] = i+1;
        e[y1][x2-1] = i+1;
        e[y2-1][x1] = i+1;
        e[y2-1][x2-1] = i+1;
        for (int y = y1; y < y2; y++) {
            d1[y][x1] = i+1;
            d2[y][x2-1] = i+1;
            for (int x = x1; x < x2; x++) {
                s[y][x] = 1;
            }
        }
        for (int x = x1; x < x2; x++) {
            c1[y1][x] = i+1;
            c2[y2-1][x] = i+1;
        }
    }
    for (int j = 1; j < K; j++) s[0][j] += s[0][j-1];
    for (int i = 1; i < K; i++) {
        s[i][0] += s[i-1][0];
        for (int j = 1; j < K; j++) {
            s[i][j] += s[i-1][j];
            s[i][j] += s[i][j-1];
            s[i][j] -= s[i-1][j-1];
        }
    }
    for (int i = 0; i < K; i++) {
        int w = -1;
        for (int j = 0; j < K; j++) {
            if (c1[i][j]) {
                if (w == -1) w = j;
                c1[i][j] = w;
            } else {
                c1[i][j] = -1;
                w = -1;
            }
        }
        w = -1;
        for (int j = 0; j < K; j++) {
            if (d1[j][i]) {
                if (w == -1) w = j;
                d1[j][i] = w;
            } else {
                d1[j][i] = -1;
                w = -1;
            }
        }
    }
    for (int i = 0; i < K; i++) {
        int w = -1;
        for (int j = 0; j < K; j++) {
            if (c2[i][j]) {
                if (w == -1) w = j;
                c2[i][j] = w;
            } else {
                c2[i][j] = -1;
                w = -1;
            }
        }
        w = -1;
        for (int j = 0; j < K; j++) {
            if (d2[j][i]) {
                if (w == -1) w = j;
                d2[j][i] = w;
            } else {
                d2[j][i] = -1;
                w = -1;
            }
        }
    }
    for (int i = 0; i < K; i++) {
        tutki(0, i);
        if (v) return 0;
        tutki(i, 0);
        if (v) return 0;
    }
    cout << "NO" << endl;
}