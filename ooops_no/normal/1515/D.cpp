#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        multiset<int> st, stt;
        for (int i = 0; i < l; i++){
            int a;
            cin >> a;
            st.insert(a);
        }
        for (int i = 0; i < r; i++){
            int a;
            cin >> a;
            stt.insert(a);
        }
        for (int i = 1; i <= n; i++){
            while(st.find(i) != st.end() && stt.find(i) != stt.end()){
                st.erase(st.find(i));
                stt.erase(stt.find(i));
            }
        }
        int ans = 0, cnt = st.size(), cntt = stt.size();
        if (st.size() > stt.size()){
            map<int,int> mp;
            for (auto to : st) mp[to]++;
            for (auto to : mp){
                if (cnt - (to.second / 2) * 2 >= stt.size()){
                    cnt -= (to.second / 2) * 2;
                    ans += to.second / 2;
                }
                else{
                    ans += abs(cntt - cnt) / 2;
                    cnt = cntt;
                }
            }
        }
        else{
            map<int, int> mp;
            for (auto to : stt) mp[to]++;
            for (auto to : mp){
                if (cntt - (to.second / 2) * 2 >= st.size()){
                    cntt -= (to.second / 2) * 2;
                    ans += to.second / 2;
                }
                else{
                    ans += abs(cnt - cntt) / 2;
                    cntt = cnt;
                }
            }
        }
        cout << ans + min(cnt, cntt) + abs(cnt - cntt) << endl;
    }
    return 0;
}