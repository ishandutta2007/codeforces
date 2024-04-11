#include<iostream>
#include<cstring>
using namespace std;

const int N = 20000 + 10;
const int K = 100 + 10;

int a[N];
int n, k, p;

int d[N][50 + 3][100 + 3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> p;
    k--;
    for(int i = 1; i <= n; i++) { cin >> a[i]; a[i] %= p; }

    memset(d[0], -1, sizeof(d[0]));
    d[0][0][0] = 0;

    for(int i = 1; i <= n; i++)
        for(int cut = 0; cut <= k; cut++)
            for(int rem = 0; rem < p; rem++) {
                //d[i & 1][cut][rem] = d[(i & 1) ^ 1][cut][(rem - a[i] + p) % p];
                d[i][cut][rem] = d[i - 1][cut][(rem - a[i] + p) % p];
                if(rem == 0 && cut) {
                    for(int j = 0; j < p; j++) {
                        int add = (j + a[i]) % p;
                        //cout << add << endl;
                        //d[i & 1][cut][rem] = max(d[i & 1][cut][rem], d[(i & 1) ^ 1][cut - 1][j] + add);
                        //d[i][cut][rem] = max(d[i][cut][rem], d[i - 1][cut - 1][j] + add);
                        if(d[i - 1][cut - 1][j] > -1) d[i][cut][rem] = max(d[i][cut][rem], d[i - 1][cut - 1][j] + add);
                    }
                }

                //cout << i << ' ' << cut << ' ' << rem << ' ' << d[i][cut][rem] << endl;
            }


    int ans = 0;
    for(int rem = 0; rem < p; rem++) ans = max(ans, d[n][k][rem] + rem);
    cout << ans << '\n';
    return 0;
}