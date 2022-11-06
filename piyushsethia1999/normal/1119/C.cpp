#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;
int a[501][501] = {};
int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n, m;
    cin >> n;
    cin >> m;
    int b[501][501] = {};
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> b[i][j];
    int cn = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != b[i][j])
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    int ii[500] = {};
    int jj[500] = {};
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if (a[i][j]) {
                ii[i]++;
                jj[j]++;
            } 

    bool b1 = true;
    for (int i = 0; i < 500; ++i) {
        if (ii[i] & 1) {
            b1 = false;
        } 
        if (jj[i] & 1) {
            b1 = false;
        } 
    }
    if (b1) cout << "Yes";
    else cout << "No";
}