#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 1e3, inf = 1e9 + 100;

int n, m;

ll q[maxn][maxn];

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> q[i][j];
    if (n == 1){
        cout << 1;
        return 0;
    }
    ll sum = 0;
    for (int i = 0; i < n; i++){
        bool is = 1;
        sum = 0;
        for (int j = 0; j < n && is; j++)
            if (q[i][j] != 0)
                sum += q[i][j];
            else
                is = 0;
        if (is)
            break;
    }
    ll ans;
    for (int i = 0; i < n; i++){
        int is = n;
        ll now = 0;
        for (int j = 0; j < n; j++)
            if (q[i][j] == 0)
                is = j;
            else
                now += q[i][j];
        if (is != n){
            if (sum - now <= 0){
                cout << -1;
                return 0;
            }
            q[i][is] = sum - now;
            ans = sum - now;
            break;
        }
    }
    for (int i = 0; i < n; i++){
        ll now = 0;
        for (int j = 0; j < n; j++)
            now += q[i][j];
        if (now != sum){
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < n; i++){
        ll now = 0;
        for (int j = 0; j < n; j++)
            now += q[j][i];
        if (now != sum){
            cout << -1;
            return 0;
        }
    }
    ll now = 0;
    for (int i = 0; i < n; i++)
        now += q[i][i];
    if (now != sum){
        cout << -1;
        return 0;
    }
    now = 0;
    for (int i = 0; i < n; i++)
        now += q[i][n - i - 1];
    if (now != sum)
        cout << -1;
    else
        cout << ans;
}