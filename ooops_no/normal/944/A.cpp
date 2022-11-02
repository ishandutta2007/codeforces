#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b) swap(a, b);
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    int now = 1;
    while(v.size() > 1){
        vector<int> q;
        for (int i = 0; i < v.size() - 1; i += 2){
            if (v[i] == a && v[i + 1] == b){
                if (v.size() == 2){
                    cout << "Final!";
                    return 0;
                }
                else{
                    cout << now << endl;
                    return 0;
                }
            }
            if (v[i] == a || v[i + 1] == a){
                q.pb(a);
            }
            else if (v[i] == b || v[i + 1] == b){
                q.pb(b);
            }
            else{
                q.pb(v[i]);
            }
        }
        v = q;
        sort(v.begin(), v.end());
        now++;
    }
    return 0;
}