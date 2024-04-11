#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        deque<int> q;
        for (int i = 0; i < n; i++){
            if (q.size() == 0) q.pb(v[i]);
            else if (v[i] < q.front()){
                q.push_front(v[i]);
            }
            else{
                q.pb(v[i]);
            }
        }
        for (auto to : q) cout << to << ' ';
        cout << endl;
    }
    return 0;
}