#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll __int128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        multiset<int> st{n};
        vector<vector<int>> v(n);
        int i = 0;
        while(i + 1 < n){
            if (s[i] == s[i + 1] && s[i] != '?'){
                st.insert(i + 1);
                v[i + 1].pb(i + 1);
                i++;
            }
            else{
                if (s[i] == '?') {
                    i++;
                    continue;
                }
                if (s[i + 1] != '?'){
                    i++;
                    continue;
                }
                int j = i + 1, cnt = 0;
                while(j < n && s[j] == '?'){
                    cnt++;
                    j++;
                }
                if (j == n) break;
                if (s[i] == s[j] && cnt % 2 == 0){
                    st.insert(j);
                    v[i + 1].pb(j);
                }
                if (s[i] != s[j] && cnt % 2 == 1){
                    st.insert(j);
                    v[i + 1].pb(j);
                }
                i = j;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (auto to : v[i]) st.erase(st.find(to));
            ans += *st.begin() - i;
        }
        cout << ans << endl;
    }
    return 0;
}