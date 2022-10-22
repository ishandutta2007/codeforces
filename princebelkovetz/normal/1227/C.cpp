#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
int get(string &s, char c, int st){
    for (int i = st; i < s.size(); ++i){
        if (s[i] == c) return i;
    }
    return -1;
}
int main() {
    int tt; cin >> tt;
    while(tt--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int cur = 0;
        vector <vector <int>> ans;
        while (k > 1){
            if (s[cur] == '(' and s[cur + 1] == ')'){
                //bruh
            } else if (s[cur] == '('){
                int nxt = get(s, ')', cur + 1);
                ans.push_back({cur + 1, nxt});
                reverse(s.begin() + cur + 1, s.begin() + nxt + 1);
            } else {
                int nxt = get(s, '(', cur);
                ans.push_back({cur, nxt});
                reverse(s.begin() + cur, s.begin() + nxt + 1);
                nxt = get(s, ')', cur + 1);
                reverse(s.begin() + cur + 1, s.begin() + nxt + 1);
            }
            k--;
            cur += 2;
        }
        for (int j = cur; j < n; ++j){
            int nxt = get(s, '(', j);
            if (nxt == -1) break;
            else {
                ans.push_back({j, nxt});
                reverse(s.begin() + j, s.begin() + nxt + 1);
            }
        }
        cout << ans.size() << '\n';
        for (auto x: ans) cout << x[0] + 1 << ' ' << x[1] + 1 << '\n';
    }
    return 0;
}