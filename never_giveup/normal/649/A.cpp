#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

const ll inf = 1e18;

ll n, m, q[maxn];

int main(){
    //ifstream cin("tetris.dat");
    //ofstream cout("tetris.sol");
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    ll ans = 1;
    for (int i = 0; i < n; i++){
        ll st = 1;
        ll k = q[i];
        while (k % 2 == 0)
            k /= 2, st *= 2;
        ans = max(ans, st);
    }
    ll answer = 0;
    for (int i = 0; i < n; i++){
        if (q[i] % ans == 0)
            answer++;
    }
    cout << ans << ' ' << answer;
}