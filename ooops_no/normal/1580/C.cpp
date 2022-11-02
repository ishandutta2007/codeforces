#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int K = 500;
int add[K][K];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<int> x(n), y(n), ans(m), last(n), bal(m + 1);
    vector<vector<int>> need(n);
    set<int> st;
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < m; i++){
        int op, k;
        cin >> op >> k;
        k--;
        int a = x[k], b = y[k];
        if (op == 1){
            cnt++;
            if (a + b < K){
                last[k] = i;
                for (int f = 0; f < a; f++){
                    add[a + b][(f + i) % (a + b)]++;
                }
            }
            else{
                need[k].pb(i);
            }
        }
        else{
            cnt--;
            if (a + b < K){
                for (int f = 0; f < a; f++){
                    add[a + b][(f + last[k]) % (a + b)]--;
                }
            }
            else{
                need[k].pb(i);
            }
        }
        ans[i] = cnt;
        for (int f = 1; f < K; f++){
            ans[i] -= add[f][i % f];
        }
    }
    for (int i = 0; i < n; i++){
        if ((int)(need[i].size()) & 1){
            need[i].pb(m);
        }
        for (int j = 0; j < need[i].size(); j += 2){
            int now = need[i][j];
            while(now < need[i][j + 1]){
                if (now + x[i] - 1 < need[i][j + 1]){
                    bal[now]++;
                    bal[now + x[i]]--;
                }
                else{
                    bal[now]++;
                    bal[need[i][j + 1]]--;
                }
                now += x[i] + y[i];
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++){
        sum += bal[i];
        ans[i] -= sum;
    }
    for (int i = 0; i < m; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}