#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const ld EPS = 1e-9;

const ll llinf = 1e18 + 100;

const int maxn = 1e5 + 100, inf = 1e9 + 100;

ll w = 1e5;

ll q[40][maxn];

ll a[maxn], n, A, B, W, H;

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
	    #ifndef STR
	    //ifstream cin("a.in");
	    //ofstream cout("a.out");
	    //freopen("a.in", "r", stdin);
	    //freopen("a.out", "w", stdout);
    	    #endif // STR
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> A >> B >> W >> H >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    n = min(n, 35ll);
    q[0][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= w; j++)
            if (q[i - 1][j] != 0)
                q[i][j] = max(q[i][j], min(w, q[i - 1][j] * a[i - 1])),
                q[i][min(w, j * a[i - 1])] = max(q[i][min(w, j * a[i - 1])], q[i - 1][j]);
    for (int i = 0; i <= n; i++)
        for (ll j = 1; j <= w; j++)
            if (q[i][j] > 0){
                if (H * j >= A && W * q[i][j] >= B){
                    cout << i;
                    return 0;
                }
                if (H * j >= B && W * q[i][j] >= A){
                    cout << i;
                    return 0;
                }
            }
    cout << -1;
}