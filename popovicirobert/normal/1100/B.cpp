#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

int fr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int cnt = 0;
    for(i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if(fr[x] == 0) {
            cnt++;
        }
        fr[x]++;
        if(cnt == n) {
            for(int j = 1; j <= n; j++) {
                fr[j]--;
                if(fr[j] == 0) {
                    cnt--;
                }
            }
            cout << 1;
        }
        else {
            cout << 0;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}