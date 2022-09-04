#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 100, mod1 = 1e9 + 993, mod2 = 42424243;

int n, k;

string s;

map<pair<int, int>, int> mp;

ll h[2][maxn], X[2][maxn];

ll make1(ll a){
    a %= mod1;
    if (a < 0)
        a += mod1;
    return a;
}

ll make2(ll a){
    a %= mod2;
    if (a < 0)
        a += mod2;
    return a;
}

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> k >> s;
    int g;
    cin >> g;
    X[0][0] = 1;
    for (int i = 1; i < maxn; i++)
        X[0][i] = (X[0][i - 1] * 43) % mod1;
    X[1][0] = 1;
    for (int i = 1; i < maxn; i++)
        X[1][i] = (X[1][i - 1] * 239) % mod2;
    for (int i = 0; i < g; i++){
        string t;
        cin >> t;
        ll hnow = 0;
        for (int j = 0; j < k; j++)
            hnow = (hnow * X[0][1] + t[j] - 'a' + 1) % mod1;
        ll hnow2 = 0;
        for (int j = 0; j < k; j++)
            hnow2 = (hnow2 * X[1][1] + t[j] - 'a' + 1) % mod2;
        mp[make_pair(hnow, hnow2)] = i + 1;
    }
    for (int i = 0; i < k; i++)
        h[0][0] = (h[0][0] * X[0][1] + s[i] - 'a' + 1) % mod1;
    for (int i = 1; i < n * k; i++)
        h[0][i] = (make1(h[0][i - 1] - (s[i - 1] - 'a' + 1) * X[0][k - 1]) * X[0][1] + s[(i + k - 1) % (n * k)] - 'a' + 1) % mod1;
    for (int i = 0; i < k; i++)
        h[1][0] = (h[1][0] * X[1][1] + s[i] - 'a' + 1) % mod2;
    for (int i = 1; i < n * k; i++)
        h[1][i] = (make2(h[1][i - 1] - (s[i - 1] - 'a' + 1) * X[1][k - 1]) * X[1][1] + s[(i + k - 1) % (n * k)] - 'a' + 1) % mod2;
    for (int start = 0; start < k; start++){
        vector<pair<int, pair<int, int> > > answer;
        bool is = 1;
        for (int i = start; i < n * k; i += k)
            if (mp.find(make_pair(h[0][i], h[1][i])) != mp.end() && mp[make_pair(h[0][i], h[1][i])] != -1)
                answer.push_back(make_pair(mp[make_pair(h[0][i], h[1][i])], make_pair(h[0][i], h[1][i]))), mp[make_pair(h[0][i], h[1][i])] = -1;
            else{
                is = 0;
                for (int j = 0; j < answer.size(); j++)
                    mp[answer[j].second] = answer[j].first;
                break;
            }
        if (is){
            cout << "YES\n";
            for (int i = 0; i < answer.size(); i++)
                cout << answer[i].first << ' ';
            return 0;
        }
    }
    cout << "NO";
}