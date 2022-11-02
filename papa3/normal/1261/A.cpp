#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

const int INF = 1000000000000000000ll;
const int mod = 1000000007;

struct Algo {
    int n, k;
    string t, s;
    
    Algo() {
        cin >> n >> k;
        cin >> s;
        for (int i = 1; i < k; i++) {
            t += "()";
        }
        for (int i = 0; i < n / 2 - (k - 1); i++) {
            t += "(";
        }
        for (int i = 0; i < n / 2 - (k - 1); i++) {
            t += ")";
        }
        //cout << s << endl;
        //cout << t << endl;
        
        vector<pair<int, int> > res;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                int j = i + 1;
                while (s[i] == s[j]) j++;
                swap(s[i], s[j]);
                res.push_back({i + 1, j + 1});
            }
        }
        
        cout << res.size() << "\n";
        for (pair<int, int> &i : res) {
            cout << i.first << " " << i.second << "\n";
        }
        //cout << s << endl;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        Algo p;
    }
    
    return 0;
}