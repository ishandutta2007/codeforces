#include <bits/stdc++.h>
using namespace std;
 
string process(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            s[i] = tolower(s[i]);
        }
 
        if (s[i] == 'o') {
            s[i] = '0';
        }
        else if (s[i] == 'i' || s[i] == 'l') {
            s[i] = '1';
        }
    }
 
    return s;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s, t;
 
    cin >> s >> n;
 
    s = process(s);
 
    while (n--) {
        cin >> t;
 
        t = process(t);
        if (s == t) {
            cout << "No\n";
            return 0;
        }
    }
 
    cout << "Yes\n";
 
    return 0;
}