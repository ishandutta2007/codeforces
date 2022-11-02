#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, m;
vector<vector<int>> v;
vector<vector<int>> ans;
vector<pair<int,int>> d{{0, 0}, {1, 0}, {0, 1}, {1, 1}};

void func(int i, int j){
    while(1){
        int cnt = v[i][j] + v[i + 1][j] + v[i + 1][j + 1] + v[i][j + 1];
        if (cnt == 0) break;
        int one, zero;
        vector<int> u;
        if (cnt == 4){
            one = 3, zero = 0;
        }
        if  (cnt == 3){
            one = 3, zero = 0;
        }
        if (cnt == 2){
            one = 1, zero = 2;
        }
        if (cnt == 1){
            one = 1, zero = 2;
        }
        for (auto to : d){
            if (v[i + to.first][j + to.second] == 1 && one > 0){
                v[i + to.first][j + to.second] = 0;
                one--;
                u.pb(i + to.first + 1);
                u.pb(j + to.second + 1);
            }
            else if (v[i + to.first][j + to.second] == 0 && zero > 0){
                v[i + to.first][j + to.second] = 1;
                zero--;
                u.pb(i + to.first + 1);
                u.pb(j + to.second + 1);
            }
        }
        ans.pb(u);
    }
}

void solve(){
    cin >> n >> m;
    ans.clear();
    v.resize(n);
    for (int i = 0; i < n; i++){
        v[i].resize(m);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c;
            cin >> c;
            v[i][j] = c - '0';
        }
    }
    if (n % 2 == 0 && m % 2 == 0){
        for (int i = 0; i < n; i += 2){
            for (int j = 0; j < m; j += 2){
                func(i, j);
            }
        }
        cout << ans.size() << endl;
        for (auto to : ans){
            for (auto t : to){
                cout << t << " ";
            }
            cout << endl;
        }
        return ;
    }
    if (n % 2 == 1 && m % 2 == 1){
        for (int i = 0; i < n - 1; i += 2){
            for (int j = 0; j < m - 1; j += 2){
                func(i, j);
            }
        }
        for (int j = 1; j < m - 1; j++){
            int sum = v[n - 1][j - 1] + v[n - 2][j - 1], sum1 = v[n - 1][j] + v[n - 2][j];
            if (sum == 0) continue;
            if (sum == 2){
                vector<int> u;
                u.pb(n);
                u.pb(j);
                u.pb(n - 1);
                u.pb(j);
                u.pb(n);
                u.pb(j + 1);
                v[n - 1][j - 1] = v[n - 2][j - 1] = 0;
                v[n - 1][j] ^= 1;
                ans.pb(u);
            }
            else{
                vector<int> u;
                if (v[n - 1][j - 1] == 1){
                    u.pb(n);
                    u.pb(j);
                    v[n - 1][j - 1] ^= 1;
                }
                else{
                    u.pb(n - 1);
                    u.pb(j);
                    v[n - 2][j - 1] ^= 1;
                }
                u.pb(n - 1);
                u.pb(j + 1);
                u.pb(n);
                u.pb(j + 1);
                v[n - 2][j] ^= 1;
                v[n - 1][j] ^= 1;
                ans.pb(u);
            }
        }
        for (int i = 1; i < n - 1; i++){
            int sum = v[i - 1][m - 1] + v[i - 1][m - 2], sum1 = v[i][m - 1] + v[i][m - 2];
            if (sum == 0) continue;
            if (sum + sum1 == 4){
                vector<int> u;
                v[i - 1][m - 1] = 0;
                v[i - 1][m - 2] = 0;
                v[i][m - 2] = 0;
                u.pb(i);
                u.pb(m);
                u.pb(i);
                u.pb(m - 1);
                u.pb(i + 1);
                u.pb(m - 1);
                ans.pb(u);
                continue;
            }
            if (sum == 2){
                vector<int> u;
                v[i - 1][m - 1] = v[i - 1][m - 2] = 0;
                u.pb(i);
                u.pb(m);
                u.pb(i);
                u.pb(m - 1);
                if (v[i][m - 2] == 1){
                    u.pb(i + 1);
                    u.pb(m - 1);
                    v[i][m - 2] ^= 1;
                }
                else{
                    u.pb(i + 1);
                    u.pb(m);
                    v[i][m - 1] ^= 1;
                }
                ans.pb(u);
            }
            else{
                vector<int> u;
                if (v[i - 1][m - 1] == 1) {
                    u.pb(i);
                    u.pb(m);
                    v[i - 1][m - 1] ^= 1;
                }
                else {
                    u.pb(i);
                    u.pb(m - 1);
                    v[i - 1][m - 2] ^= 1;
                }
                u.pb(i + 1);
                u.pb(m);
                u.pb(i + 1);
                u.pb(m - 1);
                v[i][m - 1] ^= 1;
                v[i][m - 2] ^= 1;
                ans.pb(u);
            }
        }
        func(n - 2, m - 2);
        cout << ans.size() << endl;
        for (auto to : ans){
            for (auto t : to){
                cout << t << " ";
            }
            cout << endl;
        }
        return ;
    }
    bool x = 0;
    if (n % 2 == 0){
        x = 1;
        vector<vector<int>> a(m, vector<int>(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                a[j][i] = v[i][j];
            }
        }
        swap(n, m);
        v = a;
    }
    {
        ans.clear();
        for (int i = 0; i < n - 1; i += 2){
            for (int j = 0; j < m; j += 2){
                func(i, j);
            }
        }
        for (int j = 0; j < m; j += 2){
            func(n - 2, j);
        }
        if (ans.size() <= n * m){
            cout << ans.size() << endl;
            for (auto to : ans){
                for (int i = 0; i < to.size(); i += 2){
                    if (x){
                        cout << to[i + 1] << " " << to[i] << " ";
                    }
                    else{
                        cout << to[i] << " " << to[i + 1] << " ";
                    }
                }
                cout << endl;
            }
            return;
        }
        else{
            for (auto to : ans){
                for (int i = 0; i < to.size(); i += 2){
                    v[to[i] - 1][to[i + 1] - 1] ^= 1;
                }
            }
        }
        ans.clear();
        reverse(v.begin(), v.end());
        for (int i = 0; i < n - 1; i += 2){
            for (int j = 0; j < m; j += 2){
                func(i, j);
            }
        }
        for (int j = 0; j < m; j += 2){
            func(n - 2, j);
        }
        cout << ans.size() << endl;
        for (auto to : ans){
            for (int i = 0; i < to.size(); i += 2){
                if (x){
                    cout << to[i + 1] << " " << n - to[i] + 1 << " ";
                }
                else{
                    cout << n - to[i] + 1 << " " << to[i + 1] << " ";
                }
            }
            cout << endl;
        }
        return;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}