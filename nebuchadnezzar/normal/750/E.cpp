#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 2e5 + 5;

int arr[5][5][MAXN * 3];
int cnt = 0;

int doit(int n, int num) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            arr[i][j][cnt] = -1;
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int k = i; k < 5; ++k) {
            for (int j = k; j < 5; ++j) {
                if (arr[i][k][n] != -1 && arr[k][j][num] != -1) {
                    int tmp = arr[i][k][n] + arr[k][j][num];
                    if (arr[i][j][cnt] == -1 || arr[i][j][cnt] > tmp) {
                        arr[i][j][cnt] = tmp;
                    }
                }
            }
        }
    }
    return cnt++;
}

int doit(int n, int num, int res) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            arr[i][j][res] = -1;
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int k = i; k < 5; ++k) {
            for (int j = k; j < 5; ++j) {
                if (arr[i][k][n] != -1 && arr[k][j][num] != -1) {
                    int tmp = arr[i][k][n] + arr[k][j][num];
                    if (arr[i][j][res] == -1 || arr[i][j][res] > tmp) {
                        arr[i][j][res] = tmp;
                    }
                }
            }
        }
    }
    return res;
}

int bdv;

int empty = 0;

int n, q;
char s[MAXN];
vector<int> rsq;

int get(int v, int vl, int vr, int l, int r) {
    if (r <= vl || vr <= l) {
        return empty;
    }
    if (l <= vl && vr <= r) {
        return v;
    }
    int vm = (vl + vr) / 2;
    return doit(get(v * 2, vl, vm, l, r), get(v * 2 + 1, vm, vr, l, r));
}

int main() {
    memset(arr, -1, sizeof arr);
    for (int i = 0; i < 5; ++i) {
        arr[i][i][0] = 0;
    }

    cnt = 1;
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &q);
    scanf("%s", s);

    bdv = 1;
    while (bdv < n) {
        bdv *= 2;
    }

    rsq.resize(bdv * 2);

    for (int i = 0; i < n; ++i) {
        //rsq[i + bdv] = empty;
        for (int j = 0; j < 5; ++j) {
            arr[j][j][i + bdv] = 0;
        }
        if (s[i] == '2') {
            arr[0][0][i + bdv] = 1;
            arr[0][1][i + bdv] = 0;
        } else if (s[i] == '0') {
            arr[1][1][i + bdv] = 1;
            arr[1][2][i + bdv] = 0;
        } else if (s[i] == '1') {
            arr[2][2][i + bdv] = 1;
            arr[2][3][i + bdv] = 0;
        } else if (s[i] == '7') {
            arr[3][3][i + bdv] = 1;
            arr[3][4][i + bdv] = 0;
        } else if (s[i] == '6') {
            arr[3][3][i + bdv] = 1;
            arr[4][4][i + bdv] = 1;
            //rsq[i + bdv].m[3][5] = 0;
            //rsq[i + bdv].m[4][5] = 0;
        }
    }

    for (int i = bdv - 1; i > 0; --i) {
        //rsq[i] = rsq[i * 2] + rsq[i * 2 + 1];
        doit(i * 2, i * 2 + 1, i);
    }

    cerr << clock() << endl;

    cnt = bdv * 2;

    int was = cnt;

    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        cnt = was;
        int tmp = get(1, 0, bdv, l, r);
        cout << arr[0][4][tmp] << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}