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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        while(m--){
            vector<int> a;
            for (int i = 0; i < n; i++){
                if (s[i] == '0'){
                    int sum = 0;
                    if ((i > 0 && s[i - 1] == '1')) sum++;
                    if ((i + 1 < n && s[i + 1] == '1')) sum++;
                    if (sum == 1) a.pb(i);
                }
            }
            if (a.size() == 0) break;
            for (auto to : a){
                s[to] = '1';
            }
        }
        cout << s << endl;
    }
    return 0;
}