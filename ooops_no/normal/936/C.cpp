#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

bool check(string s, string t){
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

string func(string s, int k){
    string ans = "", t = "";
    for (int i = k; i < s.size(); i++){
        ans += s[i];
    }
    for (int i = 0; i < k; i++){
        t += s[i];
    }
    reverse(t.begin(), t.end());
    ans += t;
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (!check(s, t)){
        cout << -1 << endl;
    }
    else{
        int type = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if (type == 0){
                for (int j = i; j < n; j++){
                    if (t[j] == s[i]){
                        ans.pb(j);
                        t = func(t, j);
                        ans.pb(n);
                        t = func(t, n);
                        break;
                    }
                }
                ans.pb(i);
                t = func(t, i);
                type = 1;
            }
            else if (type == 1){
                ans.pb(n - i);
                t = func(t, n - i);
                for (int j = i; j < n; j++){
                    if (t[j] == s[i]){
                        ans.pb(j);
                        t = func(t, j);
                        break;
                    }
                }
                ans.pb(1);
                t = func(t, 1);
                type = 2;
            }
            else{
                for (int j = 0; j < n - i; j++){
                    if (t[j] == s[i]){
                        ans.pb(j + 1);
                        t = func(t, j + 1);
                        ans.pb(n - (j + 1) - i);
                        t = func(t, n - (j + 1) - i);
                        break;
                    }
                }
                type = 0;
            }
        }
        if (type == 1){
            ans.pb(n);
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto to : ans){
            cout << to << ' ';
        }
    }
    return 0;
}