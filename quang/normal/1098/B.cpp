#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, m;
string a[2][N];
int val[200];
int cnt[2][4][N][2];
char M[10];
string finalRes[N];

pair<int, pair<int, int> > getRes(int id) {
    int res = -1;
    pair<int, int> ans;
    int nn = id ? m : n;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int x = 0; x < 4; x++) {
                if (x == i || x == j) continue;
                for (int y = x + 1; y < 4; y++) {
                    if (y == x || y == i || y == j) continue;


                    int xxx = 0;
                    for (int row = 0; row < nn; row++) {
                        if (row % 2 == 0)  xxx += max(cnt[id][i][row][0] + cnt[id][j][row][1], cnt[id][i][row][1] + cnt[id][j][row][0]);
                        else xxx += max(cnt[id][x][row][0] + cnt[id][y][row][1], cnt[id][x][row][1] + cnt[id][y][row][0]);
                    }

                    if (res < xxx) {
                        res = xxx;
                        ans = {i, j};
                    }
                }
            }
        }
    }
    return {res, ans};
}

void traceRes(int id, pair<int, int> u) {
    if (id) {
        swap(n, m);
    }
    pair<int, int> v;
    for (int i = 0; i < 4; i++) if (i != u.first && i != u.second) {
        v.first = i;
        break;
    }
    for (int i = 0; i < 4; i++) if (i != u.first && i != u.second && i != v.first) {
        v.second = i;
        break;
    }
    for (int row = 0; row < n; row++) {
        if (row % 2 == 0) {
            int i, j;
            tie(i, j) = u;
            if (cnt[id][i][row][0] + cnt[id][j][row][1] > cnt[id][i][row][1] + cnt[id][j][row][0]) {
                for (int x = 0; x < m; x++) {
                    if (x % 2) finalRes[row] += M[j];
                    else finalRes[row] += M[i];
                }
            } else {
                for (int x = 0; x < m; x++) {
                    if (x % 2) finalRes[row] +=  M[i];
                    else finalRes[row] +=  M[j];
                }
            }
        } else {    
            int i, j;
            tie(i, j) = v;

            if (cnt[id][i][row][0] + cnt[id][j][row][1] > cnt[id][i][row][1] + cnt[id][j][row][0]) {
                for (int x = 0; x < m; x++) {
                    if (x % 2) finalRes[row] += M[j];
                    else finalRes[row] += M[i];
                }
            } else {
                for (int x = 0; x < m; x++) {
                    if (x % 2) finalRes[row] += M[i];
                    else finalRes[row] += M[j];
                }
            }
        }
    }
    if (!id) {
        for (int i = 0; i < n; i++) {
            cout << finalRes[i] << '\n';
        }
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << finalRes[j][i];
            }
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    val['A'] = 0;
    val['C'] = 1;
    val['G'] = 2;
    val['T'] = 3;
    M[0] = 'A';
    M[1] = 'C';
    M[2] = 'G';
    M[3] = 'T';
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[0][i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[1][j] += a[0][i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt[0][val[a[0][i][j]]][i][j % 2]++;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cnt[1][val[a[1][i][j]]][i][j % 2]++;
        }
    }
    pair<int, pair<int, int> >foo = getRes(0);
    pair<int, pair<int, int> >bar = getRes(1);
    if (foo.first < bar.first) {
        traceRes(1, bar.second);
    } else {
        traceRes(0, foo.second);
    }
    return 0;
}