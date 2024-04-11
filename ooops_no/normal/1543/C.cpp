#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

const ld eps = 1e-9;

mt19937 rnd(51);

bool zero(ld a){
    return a < eps;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ld c, m, p, v;
        cin >> c >> m >> p >> v;
        vector<map<vector<ld>, ld>> a(201);
        a[0][{c, m, p}] = 1.0;
        ld ans = 0;
        for (int i = 0; i < 200; i++){
            for (auto t : a[i]){
                auto to = t.first;
                ans += t.second * to[2] * (ld)(i + 1);
            }
            for (auto t : a[i]){
                auto to = t.first;
                if (!zero(to[0])){
                    if (to[0] > v + eps){
                        if (!(zero(to[1]))){
                            a[i + 1][{to[0] - v, to[1] + v / 2, to[2] + v / 2}] += t.second * to[0];
                        }
                        else{
                            a[i + 1][{to[0] - v, to[1], to[2] + v}] += t.second * to[0];
                        }
                    }
                    else{
                        if (!(zero(to[1]))){
                            a[i + 1][{0.0, to[1] + to[0] / 2, to[2] + to[0] / 2}] += t.second * to[0];
                        }
                        else{
                            a[i + 1][{0.0, 0.0, to[2] + to[0]}] += t.second * to[0];
                        }
                    }
                }
                if (!(zero(to[1]))){
                    if (to[1] > v + eps){
                        if (!(zero(to[0]))){
                            a[i + 1][{to[0] + v / 2, to[1] - v, to[2] + v / 2}] += t.second * to[1];
                        }
                        else{
                            a[i + 1][{to[0], to[1] - v, to[2] + v}] += t.second * to[1];
                        }
                    }
                    else{
                        if (!(zero(to[0]))){
                            a[i + 1][{to[0] + to[1] / 2, 0.0, to[2] + to[1] / 2}] += t.second * to[1];
                        }
                        else{
                            a[i + 1][{0.0, 0.0, to[2] + to[1]}] += t.second * to[1];
                        }
                    }
                }
            }
        }
        cout << endl << endl << endl;
        cout << setprecision(30) << fixed << ans << endl;
    }
    return 0;
}