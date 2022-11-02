#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n), now(n);
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        now[i] = i;
    }
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    for (int i = n - 1; i >= 0; i--){
        int j = i, cnt = p[i];
        a[j][now[j]] = p[i];
        now[j]--;
        cnt--;
        while(cnt > 0){
            if (j + 1 < n && now[j + 1] > now[j]){
                a[j + 1][now[j + 1]] = p[i];
                now[j + 1]--;
                cnt--;
                j++;
                continue;
            }
            if (now[j] == -1) {
                j--;
                continue;
            }
            a[j][now[j]] = p[i];
            cnt--;
            now[j]--;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}