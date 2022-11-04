#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = 1000;

int mat[MAXN + 1][MAXN + 1];

struct Data {
    int l, c;
    bool operator <(const Data &other) const {
        return mat[l][c] > mat[other.l][other.c];
    }
};

vector <Data> arr;
vector <int> col[MAXN + 1];
int cnt[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> mat[i][j];
            arr.push_back({i, j});
        }
    }
    sort(arr.begin(), arr.end());
    for(auto it : arr) {
        for(auto l : col[it.c]) {
            if(l < it.l) {
                cnt[l][it.l]++;
                if(cnt[l][it.l] == 2) {
                    cout << mat[it.l][it.c];
                    return 0;
                }
            }
            else {
                cnt[it.l][l]++;
                if(cnt[it.l][l] == 2) {
                    cout << mat[it.l][it.c];
                    return 0;
                }
            }
        }
        col[it.c].push_back(it.l);
    }
    //cin.close();
    //cout.close();
    return 0;
}