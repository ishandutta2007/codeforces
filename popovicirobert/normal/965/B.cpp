#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 100;

char mat[MAXN + 1][MAXN + 1];
int sol[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, k, i, j;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = k; j <= n; j++) {
            int p = j - k + 1;
            while(p <= j && mat[i][p] == '.') {
                p++;
            }
            if(p == j + 1) {
                for(p = j - k + 1; p <= j; p++) {
                    sol[i][p]++;
                }
            }
        }
    }
    for(j = 1; j <= n; j++) {
        for(i = k; i <= n; i++) {
            int p = i - k + 1;
            while(p <= i && mat[p][j] == '.') {
                p++;
            }
            if(p == i + 1) {
                 for(p = i - k + 1; p <= i; p++) {
                    sol[p][j]++;
                 }
            }
        }
    }
    int mx = -1, l, c;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(sol[i][j] > mx) {
                mx = sol[i][j];
                l = i;
                c = j;
            }
        }
    }
    cout << l << " " << c;
    //cin.close();
    //cout.close();
    return 0;
}