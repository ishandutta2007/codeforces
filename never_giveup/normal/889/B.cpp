#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;

typedef long long ll;

typedef long double ld;

int ARND = 239, BRND = 281, CRND = 5812, XRND = 512823, YRND = 5128, MODRND = 1e9 + 993;

int myrand(){
    int ZRND = (XRND * (ll)ARND + YRND * (ll)BRND + CRND) % MODRND;
    XRND = YRND;
    YRND = ZRND;
    return ZRND;
}

const ll llinf = 2e18 + 100;

const int mod = 1e9 + 7;

int bpow(int x, ll y){
    if (y == 0)
        return 1;
    int ret = bpow(x, y >> 1);
    ret = (ret * (ll)ret) % mod;
    if (y & 1)
        ret = (ret * (ll)x) % mod;
    return ret;
}

int bdiv(int x, int y){
    return (x * (ll)bpow(y, mod - 2)) % mod;
}

const int maxn = 2e5 + 100, inf = 1e9 + 100, sq = 300;

int e[26][26];

bool have[26];

int E[26];

int n;

string s[maxn];

bool vis[26];

bool dfs(int v){
    vis[v] = 1;
    if (E[v] == -1){
        vis[v] = 0;
        return 0;
    }
    if (vis[E[v]])
        return 1;
    if (dfs(E[v]))
        return 1;
    vis[v] = 0;
    return 0;
}

bool cmp(string a, string b){
    return a[0] < b[0];
}

int main()
{
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        vector<bool> here(26);
        for (auto x : s[i])
        if (here[x - 'a']){
            cout << "NO";
            return 0;
        }
        else
            here[x - 'a'] = 1, have[x - 'a'] = 1;
        for (int j = 1; j < s[i].size(); j++)
            e[s[i][j - 1] - 'a'][s[i][j] - 'a'] = 1;
    }
    vector<int> o(26);
    for (int i = 0; i < 26; i++){
        int x = 0, y = 0;
        for (int j = 0; j < 26; j++)
            x += e[i][j], y += e[j][i];
        o[i] = y;
        if (max(x, y) > 1){
            cout << "NO";
            return 0;
        }
        E[i] = -1;
        for (int j = 0; j < 26; j++)
        if (e[i][j]){
            E[i] = j;
            break;
        }
    }
    for (int i = 0; i < 26; i++)
    if (have[i] && dfs(i)){
        cout << "NO";
        return 0;
    }
    vector<string> answer;
    for (int i = 0; i < 26; i++)
    if (have[i] && !vis[i] && o[i] == 0){
        answer.push_back("");
        int x = i;
        while (1){
            vis[x] = 1;
            answer.back().push_back(x + 'a');
            if (E[x] == -1)
                break;
            x = E[x];
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    for (auto i : answer)
        cout << i;
}