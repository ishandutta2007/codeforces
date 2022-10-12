#include <bits/stdc++.h>
using namespace std;

int n, m;
string s[111];
int a[111];

bool match(string &s, string &t) {
    if (s.size() != t.size()) return 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] != '?' && s[i] != t[i]) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> s[i];
    for (int i=0; i<m; i++) cin >> a[i], a[i]--;
    
    string pattern = s[a[0]];
    for (int i=1; i<m; i++) {
        if (pattern.size() != s[a[i]].size()) {
            cout << "No\n";            
            return 0;
        }
        
        for (int j=0; j<pattern.size(); j++) {
            if (pattern[j] == '?') continue;            
            if (pattern[j] != s[a[i]][j]) pattern[j] = '?';
        }        
    }   
    
    for (int i=0; i<n; i++) {
        bool del = 0;
        for (int j=0; j<m; j++) if (a[j] == i) del = 1;
        if (del) continue;
        
        if (match(pattern, s[i])) {
            cout << "No\n";
            return 0;
        }
    }
    
    cout << "Yes\n";
    cout << pattern << endl;
    return 0;
}