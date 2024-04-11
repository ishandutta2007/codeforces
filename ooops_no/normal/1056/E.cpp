#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

string s, t;

const int N = 1e6 + 10;
int MOD[]{1000242121, 1000287527}, p[]{29, 31};
vector<vector<int>> po(2, vector<int>(N)), h(2, vector<int>(N));

int get(int l, int r){
    int f = (h[0][r] - (h[0][l - 1] * po[0][r - l + 1]) % MOD[0] + MOD[0]) % MOD[0];
    int s = (h[1][r] - (h[1][l - 1] * po[1][r - l + 1]) % MOD[1] + MOD[1]) % MOD[1];
    return (f * MOD[1] + s);
}

bool compare(int l, int r, int ll, int rr){
    l++, r++, ll++, rr++;
    return (get(l, r) == get(ll, rr));
}

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int f = 0; f < 1; f++){
        po[f][0] = 1;
        for (int i = 1; i < N; i++){
            po[f][i] = (po[f][i - 1] * p[f]) % MOD[f];
        }
    }
    cin >> s >> t;
    for (int f = 0; f < 1; f++){
        for (int i = 0; i < t.size(); i++){
            h[f][i + 1] = (h[f][i] * p[f] + t[i]) % MOD[f];
        }
    }
    int n = s.size(), m = t.size();
    int cnt = 0, cntt = 0;
    if (s[0] != '0'){
        for (int i = 0; i < n; i++){
            s[i] ^= 1;
        }
    }
    for (int i = 0; i < n; i++){
        if (s[i] == '0') cnt++;
        else cntt++;
    }
    int ans = 0, start = 0;
    for (int i = 0; s[i] == '0'; i++){
        start++;
    }
    for (int i = 0; i < m; i++){
        int need = (m - (i + 1) * cnt);
        if (need <= 0 || need % cntt != 0){
            continue;
        }
        int len = (need / cntt), sum = 0, x = 0;
        for (int j = 0; j < s.size(); j++){
            if (s[j] == '0'){
                if (!compare(0, i, sum, sum + i)){
                    x = 1;
                    break;
                }
                sum += i + 1;
            }
            else if (!compare(start * (i + 1), start * (i + 1) + len - 1, sum, sum + len - 1)){
                x = 1;
                break;
            }
            else sum += len;
        }
        if (!x && !compare(0, i, start * (i + 1), start * (i + 1) + len - 1)) ans++;
    }
    cout << ans << endl;
    return 0;
}