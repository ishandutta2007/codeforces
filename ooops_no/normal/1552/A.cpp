#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
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
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = s;
        sort(t.begin(), t.end());
        int ans = 0;
        for (int i = 0; i < s.size(); i++){
            if (t[i] != s[i]){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}