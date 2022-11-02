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

int n, s;

int check(int a){
    int m = n - 1, ans = n;
    vector<int> d(n);
    d[0] = 1;
    for (int i = 1; i < n && m; i++){
        d[i] = min(m, d[i - 1] * a);
        m -= d[i];
    }
    for (int i = 0; i < n; i++){
        ans += d[i] * i;
    }
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    if (s < 2 * n - 1 || n * (n + 1) / 2 < s){
        cout << "No\n";
    }
    else{
        int l = 1, r = n + 1;
        while(r - l > 1){
            int mid = (r + l) / 2;
            if (check(mid) > s){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        int k = l + 1;
        if (k == 1){
            cout << "Yes\n";
            for (int i = 1; i < n; i++){
                cout << i << ' ';
            }
            return 0;
        }
        vector<int> d(n), pr(n);
        for (int i = 0; i < n; i++) pr[i] = i + (i > 0 ? pr[i - 1] : 0);
        d[0] = 1;
        s -= n;
        int have = n - 1;
        for (int i = 1; i < n; i++){
            for (int j = 1; j <= min(have, d[i - 1] * k); j++){
                int mn_val = 0, small_have = have - j, mx_val = pr[i + small_have] - pr[i];
                int vall = j;
                for (int f = i + 1; f < n && small_have; f++){
                    vall = min(vall * k, small_have);
                    mn_val += vall * f;
                    small_have -= vall;
                }
                if (mn_val + j * i <= s && mx_val + j * i){
                    d[i] = j;
                    have -= j;
                    s -= j * i;
                    break;
                }
            }
        }
        set<pair<int,int>> st;
        cout << "Yes\n";
        int now = 2;
        for (int i = 1; i < n; i++){
            st.clear();
            for (int j = now - d[i - 1]; j < now; j++){
                st.insert({j, k});
            }
            now += d[i];
            for (int f = 0; f < d[i]; f++){
                cout << st.begin()->first << ' ';
                pair<int,int> p = *st.begin();
                st.erase(p);
                p.second--;
                if (p.second) st.insert(p);
            }
        }
    }
    return 0;
}