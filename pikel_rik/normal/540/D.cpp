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
const int N = 1e2 + 1;

int r, s, p;
double dp[101][101][101];

double recurse(int i, int j, int k) {
    if (i == 0 or i < 0 or j < 0 or k < 0)
        return 0;
    if (j == 0 and k == 0)
        return 1;

    if (dp[i][j][k] != 2)
        return dp[i][j][k];

    double p1 = ((double)(2 * i * j) / ((i + j + k) * (i + j + k - 1))) * recurse(i, j - 1, k);
    double p2 = ((double)(2 * j * k) / ((i + j + k) * (i + j + k - 1))) * recurse(i, j, k - 1);
    double p3 = ((double)(2 * k * i) / ((i + j + k) * (i + j + k - 1))) * recurse(i - 1, j, k);
    double p4 = ((double)(i * (i - 1) + j * (j - 1) + k * (k - 1)) / ((i + j + k) * (i + j + k - 1)));

    return dp[i][j][k] = (p1 + p2 + p3) / (1 - p4);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> s >> p;

    for (int i = 0; i <= 100; i++) for (int j = 0; j <= 100; j++) for (int k = 0; k <= 100; k++) dp[i][j][k] = 2;

    double p1 = recurse(r, s, p);
    double p2 = recurse(s, p, r); //r->s->p->r, s->p->r->s
    double p3 = recurse(p, r, s);

    cout << fixed << setprecision(10);
    cout << p1 << " " << p2 << " " << p3;
    return 0;
}