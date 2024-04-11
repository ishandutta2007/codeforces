#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-7;

int run() {
    string s;
    cin >> s;
    s += "a";
    ll ans = 0;
    
    ll cur_num = -1;
    int last_dot = -INF;
    
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '.') {
            last_dot = i;
            continue;
        }
        
        if ('a' <= s[i] && s[i] <= 'z') {
            if (cur_num != -1) {
                if (i - last_dot != 3) {
                    cur_num *= 100;
                }
                
                ans += cur_num;
            }
            
            cur_num = -1;
            continue;
        }
        
        if (cur_num == -1) {
            cur_num = s[i] - '0';
        } else {
            cur_num = cur_num * 10 + (s[i] - '0');
        }
    }
    
    if (ans % 100 == 0) {
        string t = to_string(ans / 100);
        vector<char> pp;
        for (int i = 0; i < (int) t.size(); i++) {
            int j = (int) t.size() - i - 1;
            if (i % 3 == 0 && i != 0) {
                pp.push_back('.');
            }
            pp.push_back(t[j]);
        }
        
        reverse(pp.begin(), pp.end());
        for (char c : pp) {
            cout << c;
        }
        
        cout << "\n";
    } else {
        string t = to_string(ans / 100);
        vector<char> pp;
        for (int i = 0; i < (int) t.size(); i++) {
            int j = (int) t.size() - i - 1;
            if (i % 3 == 0 && i != 0) {
                pp.push_back('.');
            }
            pp.push_back(t[j]);
        }
        
        reverse(pp.begin(), pp.end());
        for (char c : pp) {
            cout << c;
        }
        
        string tt = to_string(ans % 100);
        while ((int) tt.size() < 2) {
            tt = "0" + tt;
        }
        
        cout << '.' << tt << "\n";
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}