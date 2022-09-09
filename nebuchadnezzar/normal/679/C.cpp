#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 505;

int n, k;
int field[MAXN][MAXN];
bool used[MAXN][MAXN];
int color[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

char s[MAXN];

bool on_field(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n && !field[x][y];
}

int counter = 0;

int dfs(int x, int y, int c) {
    ++counter;
    used[x][y] = 1;        
    color[x][y] = c;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (on_field(nx, ny) && !used[nx][ny]) {
            dfs(nx, ny, c);
        }
    }
    return 0;
}

vector<int> szs;
int now[MAXN * MAXN];

int sum = 0;
void add(int x, int y) {
    //cerr << "add " << x << " " << y << endl;
    int tmp = color[x][y];
    if (!now[tmp]) {
        sum += szs[tmp];
    }
    now[tmp]++;
}

void rem(int x, int y) {
    //cerr << "rem " << x << " " << y << endl;
    int tmp = color[x][y];
    now[tmp]--;
    if (!now[tmp]) {
        sum -= szs[tmp];
    }
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < n; ++j) {
            field[i][j] = (s[j] == 'X');
        }
    }

    int c = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!used[i][j]) {
                if (field[i][j]) {
                    color[i][j] = c++;
                    szs.puba(1);
                } else {
                    counter = 0;
                    dfs(i, j, c);
                    ++c;
                    szs.puba(counter);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n - k + 1; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int j2 = 0; j2 < k; ++j2) {
                add(i + j, j2);
            }
        }
        for (int j = 0; j < k; ++j) {
            if (on_field(i + j, k)) {
                add(i + j, k);
            }
            if (on_field(i - 1, j)) {
                add(i - 1, j);
            }
            if (on_field(i + k, j)) {
                add(i + k, j);
            }
        }
        ans = max(ans, sum);
        //cerr << sum << " ";
        for (int j = 0; j < n - k; ++j) {
            for (int j2 = 0; j2 < k; ++j2) {
                if (!on_field(i + j2, j)) {
                    rem(i + j2, j);
                }
                if (!on_field(i + j2, j + k)) {
                    add(i + j2, j + k);
                }
            }
            if (on_field(i - 1, j + k)) {
                add(i - 1, j + k);
            }
            if (on_field(i - 1, j)) {
                rem(i - 1, j);
            }
            if (on_field(i + k, j + k)) {
                add(i + k, j + k);
            }
            if (on_field(i + k, j)) {
                rem(i + k, j);
            }
            for (int j2 = 0; j2 < k; ++j2) {
                if (on_field(i + j2, j - 1)) {
                    rem(i + j2, j - 1);
                }
                if (on_field(i + j2, j + k + 1)) {
                    add(i + j2, j + k + 1);
                }
            }
            ans = max(ans, sum);
            //cerr << sum << " ";
        }
        //cerr << endl;

        for (int j = 0; j < k; ++j) {
            for (int j2 = 0; j2 < k; ++j2) {
                rem(i + j, n - j2 - 1);
            }
        }
        for (int j = 0; j < k; ++j) {
            if (on_field(i + j, n - k - 1)) {
                rem(i + j, n - k - 1);
            }
            if (on_field(i - 1, n - j - 1)) {
                rem(i - 1, n - j - 1);
            }
            if (on_field(i + k, n - j - 1)) {
                rem(i + k, n - j - 1);
            }
        }
        /*
        for (int j = 0; j < c; ++j) {
            cerr << now[j] << " ";
        }
        cerr << endl;*/
    }

    cout << ans << "\n";

    return 0;
}