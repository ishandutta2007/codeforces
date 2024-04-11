#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<deque>

using namespace std;

#define pb push_back
#define int long long
#define ld long double

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n), used(n);
        int j = 0;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            if (v[i] > v[j]){
                j = i;
            }
        }
        used[j] = 1;
        vector<int> ans;
        int now = v[j];
        ans.pb(v[j]);
        for (int q = 1; q < n; q++){
            int j = -1;
            for (int i = 0; i < n; i++){
                if (!used[i] && (j == -1 || __gcd(v[i], now) > __gcd(now, v[j]))){
                    j = i;
                }
            }
            used[j] = 1;
            ans.pb(v[j]);
            now = __gcd(now, v[j]);
        }
        for (auto to : ans){
            cout << to << " ";
        }
        cout << endl;
    }
    return 0;
}