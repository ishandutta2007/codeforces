#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

int n, q;

void solve(){
    int sum = 0;
    vector<int> po(20);
    po[1] = 1;
    for (int i = 2; i < 20; i++){
        po[i] = po[i - 1] * i;
    }
    while(q--){
        int t;
        cin >> t;
        if (t == 2){
            int x;
            cin >> x;
            sum += x;
        }
        else{
            int l, r;
            cin >> l >> r;
            int need = sum;
            set<int> st;
            vector<int> u;
            for (int i = 1; i <= n; i++) st.insert(i);
            for (int i = 0; i < n; i++){
                if (need == 0){
                    u.pb(*st.begin());
                    st.erase(st.begin());
                }
                else{
                    int val = 0;
                    for (auto to : st){
                        if (need < po[n - i - 1]){
                            val = to;
                            break;
                        }
                        else{
                            need -= po[n - i - 1];
                        }
                    }
                    u.pb(val);
                    st.erase(val);
                }
            }
            int ans = 0;
            for (int i = l - 1; i < r; i++){
                ans += u[i];
            }
            cout << ans << endl;
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    if (n < 20){
        solve();
    }
    else{
        vector<int> po(20, 1);
        for (int i = 1; i < 20; i++){
            po[i] = po[i - 1] * i;
        }
        int need = 0, sum = 0;
        while(q--){
            int t;
            cin >> t;
            if (t == 2){
                int x;
                cin >> x;
                sum += x;
            }
            else{
                int l, r;
                cin >> l >> r;
                int pos = min(n - 20, r), ans = 0;
                if (l <= pos){
                    ans += pos * (pos + 1) / 2 - l * (l - 1) / 2;
                }
                set<int> st;
                for (int i = n - 20 + 1; i <= n; i++) st.insert(i);
                int need = sum;
                for (int i = n - 20; i < n; i++){
                    int kek = 0;
                    if (need == 0){
                        kek = *st.begin();
                        st.erase(kek);
                    }
                    else{
                        for (auto to : st){
                            if (need < po[n - i - 1]){
                                kek = to;
                                break;
                            }
                            else{
                                need -= po[n - i - 1];
                            }
                        }
                        st.erase(kek);
                    }
                    if (l <= i + 1 && i + 1 <= r){
                        ans += kek;
                    }
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}