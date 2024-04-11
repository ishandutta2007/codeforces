#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e3;

int n, m;
string a[N];

bool visited[1000][1000];

void dfs(int i, int j) {
    visited[i][j] = true;

    if (i > 0 and !visited[i - 1][j] and a[i-1][j] == '#') dfs(i - 1, j);
    if (j > 0 and !visited[i][j - 1] and a[i][j-1] == '#') dfs(i, j - 1);
    if (i + 1 < n and !visited[i + 1][j] and a[i+1][j] == '#') dfs(i + 1, j);
    if (j + 1 < m and !visited[i][j + 1] and a[i][j+1] == '#') dfs(i, j + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<bool> good1(n), good2(m);
    bool flag = false, flag1 = false;

    for (int i = 0; i < n; i++) {
        flag = flag1 = false;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                if (flag1) {
                    cout << "-1\n";
                    return 0;
                }
                good1[i] = true;
                good2[j] = true;
                flag = true;
            }
            else if (flag) {
                flag1 = true;
            }
        }
    }

    flag = flag1 = false;

    for (int j = 0; j < m; j++) {
        flag = flag1 = false;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == '#') {
                if (flag1) {
                    cout << "-1\n";
                    return 0;
                }
                flag = true;
            }
            else if (flag) {
                flag1 = true;
            }
        }
    }

    vector<bool> temp1(n), temp2(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                if (!good1[i] and !good2[j]) {
                    temp1[i] = true;
                    temp2[j] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!good1[i] and !temp1[i]) {
            cout << "-1\n";
            return 0;
        }
    }

    for (int j = 0; j < m; j++) {
        if (!good2[j] and !temp2[j]) {
            cout << "-1\n";
            return 0;
        }
    }


    int c = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] and a[i][j] == '#') {
                dfs(i, j);
                c += 1;
            }
        }
    }

    cout << c << "\n";

    return 0;
}