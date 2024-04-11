#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

const ll inf = 1e18;

int n, q[maxn];

int st = 0;

int main(){
    //ifstream cin("tetris.dat");
    //ofstream cout("tetris.sol");
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    int l = 0;
    int ans = 0;
    while (l < n){
        while (st < n && q[st] != 0)
            st++;
        int r = l;
        if (q[l] == 0){
            l++;
            continue;
        }
        while (r < n - 1 && q[r + 1] == q[l])
            r++;
        for (int i = r; i >= l; i--){
            if (st >= l)
                break;
            q[st] = q[i];
            q[i] = 0;
            st++;
            ans++;
        }
        l = r + 1;
    }
    cout << ans;
}