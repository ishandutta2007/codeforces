#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> st;
    for (int i = 0; i + 2 < n; i++){
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c'){
            st.insert(i);
        }
    }
    while(q--){
        int i;
        char c;
        cin >> i >> c;
        i--;
        s[i] = c;
        for (int j = max(0ll, i - 5); j + 2 < min(n, i + 5); j++){
            st.erase(j);
            if (s[j] == 'a' && s[j + 1] == 'b' && s[j + 2] == 'c'){
                st.insert(j);
            }
        }
        cout << st.size() << endl;
    }
    return 0;
}