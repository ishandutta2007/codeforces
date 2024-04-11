#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
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
        string n;
        cin >> n;
        int ans = n.size();
        for (int i = 0; i < n.size(); i++){
            for (int j = i + 1; j < n.size(); j++){
                if ((int)((n[i] - (int)'0') * 10 + (n[j] - (int)'0')) % 25 == 0){
                    ans = min(ans, (int)(n.size()) - i - 2);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}