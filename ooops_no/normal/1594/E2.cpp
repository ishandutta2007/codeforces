#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 1e9 + 7;
vector<vector<int>> DP;
map<int, vector<int>> ans;

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int mul(int a, int b){
    return (a * b % MOD);
}

void func(){
    vector<int> dp(6, 1);
    for (int i = 1; i < 62; i++){
        DP.pb(dp);
        vector<int> dpp(6);
        for (int j = 0; j < 6; j++){
            for (int l = 0; l < 6; l++){
                for (int f = 0; f < 6; f++){
                    if (j == l || j == f) continue;
                    if ((j ^ l) == 1 || (j ^ f) == 1) continue;
                    dpp[j] = add(dpp[j], mul(dp[l], dp[f]));
                }
            }
        }
        dp = dpp;
    }
}

int check(string s){
    if (s == "white") return 0;
    if (s == "yellow") return 1;
    if (s == "green") return 2;
    if (s == "blue") return 3;
    if (s == "red") return 4;
    if (s == "orange") return 5;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    func();
    int k, n;
    cin >> k >> n;
    int need = (1LL << k) - 1;
    vector<set<int>> sz(k + 1);
    map<int,int> val;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        string s;
        cin >> s;
        int st_a = a;
        int now = 0;
        while (a * 2 <= need){
            a *= 2;
            now++;
        }
        val[st_a] = check(s) + 1;
        sz[now].insert(st_a);
    }
    for (int i = 0; i < k; i++){
        for (auto to : sz[i]){
            sz[i + 1].insert(to / 2);
            if (i == 0){
                ans[to] = vector<int>(6, 0);
                ans[to][val[to] - 1] = 1;
                continue;
            }
            vector<int> dp, dpp;
            vector<int> kek(6);
            if (ans[to * 2].size() == 0){
                dp = DP[i - 1];
            }
            else{
                dp = ans[to * 2];
            }
            if (ans[to * 2 + 1].size() == 0){
                dpp = DP[i - 1];
            }
            else{
                dpp = ans[to * 2 + 1];
            }
            for (int f = 0; f < 6; f++){
                for (int k = 0; k < 6; k++){
                    if (f == k || (f ^ k) == 1) continue;
                    for (int l = 0; l < 6; l++){
                        if (f == l || (f ^ l) == 1) continue;
                        kek[f] = add(kek[f], mul(dp[k], dpp[l]));
                    }
                }
            }
            for (int i = 0; i < 6; i++){
                if (val[to] > 0 && i != val[to] - 1){
                    kek[i] = 0;
                }
            }
            ans[to] = kek;
        }
    }
    int anss = 0;
    for (int i = 0; i < 6; i++){
        anss = add(anss, ans[1][i]);
    }
    cout << anss << endl;
    return 0;
}