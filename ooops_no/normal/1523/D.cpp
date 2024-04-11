#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> po(61), sum(n);
    po[0] = 1;
    for (int i = 1; i < 61; i++) po[i] = po[i - 1] * 2;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            if (s[j] == '1'){
                sum[i] += po[j];
            }
        }
    }
    random_shuffle(sum.begin(), sum.end());
    int anss = 0;
    for (int i = 0; i < min(n, 130ll); i++){
        vector<int> a;
        for (int j = 0; j < m; j++){
            if ((sum[i] >> j) & 1) a.pb(j);
        }
        vector<int> ans(1 << a.size());
        for (int j = 0; j < n; j++){
            int cnt = 0;
            for (int k = 0; k < a.size(); k++){
                if ((sum[j] >> a[k]) & 1){
                    cnt += (1 << k);
                }
            }
            ans[cnt]++;
        }
        for (int f = 0; f < a.size(); f++){
            for (int j = 0; j < ans.size(); j++){
                if (j & (1 << f)) ans[j ^ (1 << f)] += ans[j];
            }
        }
        for (int j = 0; j < ans.size(); j++){
            if (ans[j] * 2 >= n){
                int now = 0;
                for (int k = 0; k < a.size(); k++){
                    if (j & (1 << k)){
                        now += po[a[k]];
                    }
                }
                if (__builtin_popcountll(now) > __builtin_popcountll(anss)){
                    anss = now;
                }
            }
        }
    }
    for (int f = 0; f < m; f++){
        if (anss & po[f]){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    return 0;
}