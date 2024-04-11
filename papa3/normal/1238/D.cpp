#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

#define MAX_N 1000010

int pre[MAX_N][2];
char tab[MAX_N];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int res = 0;
    tab[0] = 'C';
    for (int i = 1; i <= n; i++) {
        cin >> tab[i];

        pre[i][0] = pre[i - 1][0];
        pre[i][1] = pre[i - 1][1];

        if (tab[i - 1] == 'A') pre[i][0] = i - 1;
        else pre[i][1] = i - 1;

        int a, b, bb;

        if (tab[i] == 'A') {
            a = pre[i][0];

            b = pre[i][1];
            bb = pre[b][1];
        } else {
            a = pre[i][1];


            b = pre[i][0];
            bb = pre[b][0];
        }

        res += a;
        if (b < a && b != 0) {
            res--;
        }
        //cout << res << endl;
    }

    cout << res;

    return 0;
}
/*

*/