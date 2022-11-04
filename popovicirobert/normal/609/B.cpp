#include <bits/stdc++.h>
#define ll long long



using namespace std;


int fr[11];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x, j, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> x;
        fr[x]++;
    }
    int ans = 0;
    for(i = 1; i <= m; i++)
        for(j = i + 1; j <= m; j++)
             ans += fr[i] * fr[j];
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}