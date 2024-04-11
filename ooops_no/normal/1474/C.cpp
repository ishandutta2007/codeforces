#include<bits/stdc++.h>

#define int long long
#define pb push_back
#define ld long double

using namespace std;

mt19937 rnd(51);

const int N = 1e6 + 10;
int a[N];

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n *= 2;
        vector<int> v(n), u;
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.rbegin(), v.rend());
        bool anss = 0;
        for (int i = 1; i < n; i++){
            int x = v[0];
            for (auto to : v) a[to]++;
            bool f = 0;
            a[v[i]]--;
            a[v[0]]--;
            vector<pair<int,int>> ans;
            ans.pb({v[0], v[i]});
            for (int j = 0; j < n; j++){
                if (a[v[j]] > 0){
                    a[v[j]]--;
                    if (x < v[j] || a[x - v[j]] == 0){
                        f = 1;
                        break;
                    }
                    ans.pb({v[j], x - v[j]});
                    a[x - v[j]]--;
                    x = v[j];
                }
            }
            if (!f){
                cout << "YES\n";
                cout << v[0] + v[i] << endl;
                for (auto to : ans){
                    cout << to.first << " " << to.second << endl;
                }
                anss = 1;
                break;
            }
            for (auto to : v) a[to] = 0;
        }
        if (!anss){
            cout << "NO\n";
        }
    }
    return 0;
}