#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

vector<vector<char>> v;

int cnt(string s, string t){
    int ans = 0;
    for (int i = 0; i < s.size(); i++){
        ans += (s[i] != t[i]);
    }
    return ans;
}

vector<vector<char>> make(vector<char> d, int n, int m){
    vector<vector<char>> ans(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        string s = "", t = "", k = "";
        for (int j = 0; j < m; j++){
            s += d[(i & 1) * 2 + (j & 1)];
            t += d[(i & 1) * 2 + ((j & 1) ^ 1)];
            k += v[i][j];
        }
        if (cnt(k, s) < cnt(k, t)){
            for (int j = 0; j < m; j++){
                ans[i][j] = s[j];
            }
        }
        else{
            for (int j = 0; j < m; j++){
                ans[i][j] = t[j];
            }
        }
    }
    return ans;
}

vector<vector<char>> make2(vector<char> d, int n, int m){
    vector<vector<char>> ans(n, vector<char>(m));
    for (int j = 0; j < m; j++){
        string s = "", t = "", k = "";
        for (int i = 0; i < n; i++){
            s += d[(j & 1) * 2 + (i & 1)];
            t += d[(j & 1) * 2 + ((i & 1) ^ 1)];
            k += v[i][j];
        }
        if (cnt(k, s) < cnt(k, t)){
            for (int i = 0; i < n; i++){
                ans[i][j] = s[i];
            }
        }
        else{
            for (int i = 0; i < n; i++){
                ans[i][j] = t[i];
            }
        }
    }
    return ans;
}

int dif(vector<vector<char>> a, vector<vector<char>> b){
    int ans = 0;
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[0].size(); j++){
            ans += (a[i][j] != b[i][j]);
        }
    }
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) v[i].resize(m);
    vector<char> d{'A', 'G', 'C', 'T'};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    int df = 1e18;
    vector<vector<char>> ans;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                for (int l = 0; l < 4; l++){
                    set<int> st{i, j, k, l};
                    if (st.size() < 4 || i > j || k > l) continue;
                    auto a = make(vector<char>{d[i], d[j], d[k], d[l]}, n, m);
                    if (dif(a, v) < df){
                        df = dif(a, v);
                        ans = a;
                    }
                    a = make2(vector<char>{d[i], d[j], d[k], d[l]}, n, m);
                    if (dif(a, v) < df){
                        df = dif(a, v);
                        ans = a;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}