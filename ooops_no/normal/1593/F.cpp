#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 41;
int dp[N][N][N][N], par[N][N][N][N];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        int n, a, b;
        cin >> n >> a >> b >> s;
        vector<int> poa(n), pob(n);
        poa[0] = pob[0] = 1;
        for (int i = 1; i < n; i++){
            poa[i] = (poa[i - 1] * 10) % a;
            pob[i] = (pob[i - 1] * 10) % b;
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= 40; j++){
                for (int k = 0; k <= 40; k++){
                    for (int f = 0; f <= 40; f++){
                        dp[i][j][k][f] = 0;
                    }
                }
            }
        }
        dp[0][0][0][0] = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < a; j++){
                for (int k = 0; k < b; k++){
                    for (int cola = 0; cola <= i; cola++){
                        if (!dp[i][j][k][cola]) continue;
                        int colb = i - cola;
                        int nwa = (j + poa[cola] * (s[i] - '0')) % a;
                        dp[i + 1][nwa][k][cola + 1] = 1;
                        par[i + 1][nwa][k][cola + 1] = 0;

                        int nwb = (k + pob[colb] * (s[i] - '0')) % b;
                        dp[i + 1][j][nwb][cola] = 1;
                        par[i + 1][j][nwb][cola] = 1;
                    }
                }
            }
        }
        int mn = 1e18, val = -1;
        for (int i = 0; i <= n; i++){
            int j = n - i;
            if (dp[n][0][0][i] && abs(j - i) < mn && j > 0 && i > 0){
                mn = abs(j - i);
                val = i;
            }
        }
        if (mn == 1e18){
            cout << -1 << endl;
            continue;
        }
        string ans = "";
        int vala = 0, valb = 0, cola = val;
        for (int i = n; i >= 1; i--){
            int colb = i - cola;
            if (par[i][vala][valb][cola] == 0){
                ans += 'R';
                vala = ((vala - poa[cola - 1] * (s[i - 1] - '0')) % a + a) % a;
                cola--;
            }
            else{
                ans += 'B';
                valb = ((valb - pob[colb - 1] * (s[i - 1] - '0')) % b + b) % b;
            }
        }
        cout << ans << endl;
    }
    return 0;
}