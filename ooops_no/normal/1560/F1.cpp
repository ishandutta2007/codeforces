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
#define int long long
#define ll long long

mt19937 rnd(51);

bool check(string s, int mx){
    for (int i = 0; i < s.size(); i++){
        if (s[i] - '0' > mx){
            return 0;
        }
        if (s[i] - '0' < mx){
            return 1;
        }
    }
    return 1;
}

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
        int n, k;
        cin >> n >> k;
        string s = to_string(n);
        if (k == 1){
            for (int f = 1; f <= 9; f++){
                int ans = 0;
                for (int i = 0; i < s.size(); i++){
                    ans = ans * 10 + f;
                }
                if (ans >= n){
                    cout << ans << endl;
                    break;
                }
            }
            continue;
        }
        int mx = -1;
        set<int> st;
        map<int,int> cnt;
        for (int i = 0; i < s.size(); i++){
            st.insert(s[i] - '0');
            cnt[s[i]]++;
            if (st.size() <= k && (st.size() < k || check(s.substr(i + 1, s.size() - i), *st.rbegin()))){
                mx = i;
            }
            else{
                if (cnt[s[i]] == 1){
                    st.erase(s[i] - '0');
                }
                break;
            }
        }
        for (int i = 0; i <= mx; i++){
            cout << s[i];
        }
        if (mx + 1 < s.size()){
            if (st.size() < k){
                st.insert(s[mx + 1] - '0' + 1);
            }
            for (int i = 0; i < 10; i++){
                if (st.size() < k){
                    st.insert(i);
                }
            }
            for (auto to : st){
                if (to > s[mx + 1] - '0'){
                    cout << to;
                    break;
                }
            }
            for (int i = 0; i < s.size() - mx - 2; i++){
                cout << *st.begin();
            }
            cout << endl;
        }
        else cout << endl;
    }
    return 0;
}