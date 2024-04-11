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
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0, cnt = 0;
    multiset<int> st;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] >= 0){
            sum += a[i];
            cnt++;
        }
        else{
            if (sum >= abs(a[i])){
                sum -= abs(a[i]);
                cnt++;
                st.insert(abs(a[i]));
            }
            else if (st.size() > 0 && *st.rbegin() > abs(a[i])){
                sum += *st.rbegin();
                st.erase(st.find(*st.rbegin()));
                sum -= abs(a[i]);
                st.insert(abs(a[i]));
            }
        }
    }
    cout << cnt << endl;
    return 0;
}