#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(1339);

const ll llinf = 2e18 + 100;

const int maxn = 5e3 + 10, maxw = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 300, LG = 17;

int n;

string s;

int a[26];

vector<int> q[26][maxn];

int get(int cyc, int id){
    if (id < n - cyc)
        return s[cyc + id] - 'a';
    return s[id - (n - cyc)] - 'a';
}

int main()
{
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    for (int cic = 0; cic < n; cic++){
        for (int i = 1; i < n; i++)
            q[get(cic, 0)][i].push_back(get(cic, i));
    }
    int answer = 0;
    for (int i = 0; i < 26; i++){
        int ans = 0;
        for (int j = 1; j < n; j++){
            int now = 0;
                for (auto x : q[i][j]){
                    if (a[x] == 0)
                        now++;
                    else
                    if (a[x] == 1)
                        now--;
                    a[x]++;
                }
                for (auto x : q[i][j])
                    a[x]--;
            if (now > ans)
                ans = now;
        }
        answer += ans;
    }
    cout << fixed << setprecision(20) << answer / (double)n;
}