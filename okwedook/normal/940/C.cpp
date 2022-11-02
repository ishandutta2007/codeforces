#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char> sett;
    for (auto i : s) sett.insert(i);
    char first = *sett.begin(), last;
    if (n < k) {
        cout << s;
        for (int i = n; i < k; ++i) cout << first;
        return 0;
    }
    for (char c = 'a'; c <= 'z'; ++c) 
        if (sett.count(c))
            last = c;
    string t = "";
    for (int i = 0; i < k; ++i) t += first;
    for (int i = min(t.size() - 1, s.size() - 1); i >= 0; --i) {
        if (s[i] == last) t[i] = first;
        else {
            t[i] = *sett.upper_bound(s[i]);
            break;
        }
    }
    for (int i = 0; i < n && t[i] == first; i++) t[i] = s[i];
    cout << t; 
    //system("pause");
    return 0;
}