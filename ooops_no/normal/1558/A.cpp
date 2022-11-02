#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

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
        int a, b;
        cin >> a >> b;
        set<int> st;
        for (int _ = 0; _ < 2; _++){
            for (int k = 0; k <= (a + b + 1) / 2; k++){
                if (k > b) continue;
                int need = (a + b + 1) / 2 - k;
                if (need > a) continue;
                st.insert(a - need + k);
            }
            swap(a, b);
        }
        cout << st.size() << endl;
        for (auto to : st){
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}