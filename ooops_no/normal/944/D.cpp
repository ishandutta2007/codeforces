#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    ld kol = 0;
    for (int i = 'a'; i <= 'z'; i++){
        vector<vector<int>> v(n, vector<int>(26));
        for (int j = 0; j < n; j++){
            if (s[j] == i){
                for (int k = 1; k < n; k++){
                    v[k][s[(k + j) % n] - 'a']++;
                }
            }
        }
        int mx = -1;
        for (int k = 1; k < n; k++){
            int cnt = 0;
            for (int j = 0; j < 26; j++){
                cnt += (v[k][j] == 1);
            }
            if (cnt >= mx) mx = cnt;
        }
        kol += mx;
    }
    cout << kol / n << endl;
    return 0;
}