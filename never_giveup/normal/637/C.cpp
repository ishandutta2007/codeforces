#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 993;

typedef long long ll;

const int maxn = 1000;

int q[maxn][6], n;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < 6; j++){
        char c;
        cin >> c;
        q[i][j] = c - '0';
    }
    int ans = 7;
    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++){
        int x = 0;
        for (int k = 0; k < 6; k++)
            x += (q[i][k] != q[j][k]);
        ans = min(ans, (x + 1) / 2);
    }
    ans--;
    cout << ans;
}